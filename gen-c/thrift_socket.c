/**
 * Thrift c
 *
 */

#include "thrift_socket.h"

#include <netdb.h>
#include <string.h>

gboolean _thrift_socket_open (ThriftTransport * transport,
                              GError ** error)
{
    ThriftSocket * thrift_socket = THRIFT_SOCKET (transport);
    g_assert (thrift_socket->sd == 0);

    struct hostent * hp;
    struct sockaddr_in pin;

    /* go find out about the desired host machine */
    if ((hp = gethostbyname (thrift_socket->hostname)) == 0)
    {
        /* TODO: pass through h_error info */
        g_set_error (error, THRIFT_SOCKET_ERROR, THRIFT_SOCKET_ERROR_HOST, 
                     "failed to lookup host: %s:%d", 
                     thrift_socket->hostname, thrift_socket->port);
        return 0;
    }

    /* fill in the socket structure with host information */
    memset (&pin, 0, sizeof (pin));
    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;
    pin.sin_port = htons (thrift_socket->port);

    /* grab an Internet domain socket */
    if ((thrift_socket->sd = socket (AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        /* TODO: pass through error info */
        g_set_error (error, THRIFT_SOCKET_ERROR, THRIFT_SOCKET_ERROR_SOCKET, 
                     "failed to create socket for host: %s:%d", 
                     thrift_socket->hostname, thrift_socket->port);
        return 0;
    }

    /* connect to PORT on HOST */
    if (connect (thrift_socket->sd, (struct sockaddr *)&pin, sizeof (pin)) ==
        -1)
    {
        /* TODO: pass through error info */
        g_set_error (error, THRIFT_SOCKET_ERROR, THRIFT_SOCKET_ERROR_CONNECT, 
                     "failed to connect to host: %s:%d", 
                     thrift_socket->hostname, thrift_socket->port);
        return 0;
    }

    return 1;
}

gboolean _thrift_socket_close (ThriftTransport * transport,
                               GError ** error)
{
    ThriftSocket * thrift_socket = THRIFT_SOCKET (transport);

    /* TODO: error handling */
    close (thrift_socket->sd);
    thrift_socket->sd = 0;
}

gint32 _thrift_socket_read (ThriftTransport * transport, gpointer buf,
                            guint len, GError ** error)
{
    ThriftSocket * thrift_socket = THRIFT_SOCKET (transport);

    /* TODO: look at all the stuff in TSocket.cpp */
    guint ret;
    gint got = 0;
    while (got < len)
    {
        ret = recv (thrift_socket->sd, buf, len, 0); 
        if (ret < 0)
        {
            /* TODO: pass on error info */
            g_set_error (error, THRIFT_SOCKET_ERROR, 
                         THRIFT_SOCKET_ERROR_RECEIVE, 
                         "failed to send %d bytes", len);
            return -1;
        }
        got += ret;
    }

    return got;
}

gint32 _thrift_socket_write (ThriftTransport * transport,
                             const gpointer buf, const guint len,
                             GError ** error)
{
    ThriftSocket * thrift_socket = THRIFT_SOCKET (transport);
    g_assert (thrift_socket->sd != 0);

    /* TODO: take a look at the flags stuff in TSocket.cpp */
    gint ret;
    gint sent = 0;
    while (sent < len)
    {
        ret = send (thrift_socket->sd, buf + sent, len - sent, 0);
        if (ret < 0)
        {
            /* TODO: pass on error info */
            g_set_error (error, THRIFT_SOCKET_ERROR, THRIFT_SOCKET_ERROR_SEND, 
                         "failed to send %d bytes", len);
            return -1;
        }
        sent += ret;
    }

    return sent;
}

enum _ThriftSocketProperties
{
    PROP_DUMMY,
    PROP_HOSTNAME,
    PROP_PORT
};

void _thrift_socket_set_property (GObject * object, guint property_id,
                                  const GValue * value, GParamSpec * pspec)
{
    ThriftSocket * socket = THRIFT_SOCKET (object);
    /* TODO: we could check that pspec is the type we want, not sure that's nec
     * TODO: proper error here */
    switch (property_id)
    {
        case PROP_HOSTNAME:
            socket->hostname = g_strdup (g_value_get_string (value));
            break;
        case PROP_PORT:
            socket->port = g_value_get_uint (value);
            break;
    }
}

void _thrift_socket_get_property (GObject * object, guint property_id,
                                  GValue * value, GParamSpec * pspec)
{
    ThriftSocket * socket = THRIFT_SOCKET (object);
    /* TODO: we could check that pspec is the type we want, not sure that's nec
     * TODO: proper error here */
    switch (property_id)
    {
        case PROP_HOSTNAME:
            g_value_set_string (value, socket->hostname);
            break;
        case PROP_PORT:
            g_value_set_uint (value, socket->port);
            break;
    }
}

static void _thrift_socket_instance_init (ThriftSocket * socket)
{
    socket->sd = 0;
    socket->buf_size = 256;
    socket->buf = g_new (guint8, socket->buf_size);
}

// TODO: destroy, free hostname memory, close socket, etc.


static void _thrift_socket_class_init (ThriftSocketClass * klass)
{
    GObjectClass * gobject_class = G_OBJECT_CLASS (klass);
    GParamSpec * param_spec;

    gobject_class->set_property = _thrift_socket_set_property;
    gobject_class->get_property = _thrift_socket_get_property;

    param_spec = g_param_spec_string ("hostname",
                                      "hostname (construct)",
                                      "Set the hostname of the remote host",
                                      "localhost" /* default value */,
                                      G_PARAM_CONSTRUCT_ONLY |
                                      G_PARAM_READWRITE);
    g_object_class_install_property (gobject_class, PROP_HOSTNAME, param_spec);

    param_spec = g_param_spec_uint ("port",
                                    "port (construct)",
                                    "Set the port of the remote host",
                                    0 /* min */,
                                    64000 /* max, TODO: actual max port value */,
                                    1024 /* default value */,
                                    G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);
    g_object_class_install_property (gobject_class, PROP_PORT, param_spec);

    ThriftTransportClass * thrift_transport_class = 
        THRIFT_TRANSPORT_CLASS(klass);

    thrift_transport_class->open = _thrift_socket_open;
    thrift_transport_class->close = _thrift_socket_close;
    thrift_transport_class->read = _thrift_socket_read;
    thrift_transport_class->write = _thrift_socket_write;
}

GQuark
thrift_socket_error_quark (void)
{
    return g_quark_from_static_string ("thrift-socket-error-quark");
}

GType thrift_socket_get_type (void)
{
    static GType type = 0;

    if (type == 0)
    {
        static const GTypeInfo type_info =
        {
            sizeof (ThriftSocketClass),
            NULL, /* base_init */
            NULL, /* base_finalize */
            (GClassInitFunc)_thrift_socket_class_init,
            NULL, /* class_finalize */
            NULL, /* class_data */
            sizeof (ThriftSocket),
            0, /* n_preallocs */
            (GInstanceInitFunc)_thrift_socket_instance_init,
            NULL, /* value_table */
        };

        type = g_type_register_static (THRIFT_TYPE_TRANSPORT,
                                       "ThriftSocketType",
                                       &type_info, 0);
    }

    return type;
}
