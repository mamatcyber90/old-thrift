/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */

#include "thrudoc_types.h"

gint32 thrift_thrudoc_thrudoc_exception_write (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  ThriftThrudocThrudocException * this_object = THRIFT_THRUDOC_THRUDOC_EXCEPTION(object);
  xfer += thrift_protocol_write_struct_begin (protocol, "ThrudocException", error);
  xfer += thrift_protocol_write_field_begin (protocol, "what", T_STRING, 1, error);
  xfer += thrift_protocol_write_string(protocol, this_object->what, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_begin (protocol, "type", T_I32, 2, error);
  xfer += thrift_protocol_write_i32(protocol, (gint32)this_object->type, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_stop(protocol, error);
  xfer += thrift_protocol_write_struct_end(protocol, error);
  return xfer;
}

gint32 thrift_thrudoc_thrudoc_exception_read (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  gchar * fname;
  ThriftType ftype;
  gint16 fid;

  xfer += thrift_protocol_read_struct_begin (protocol, &fname, error);
  ThriftThrudocThrudocException * this_object = THRIFT_THRUDOC_THRUDOC_EXCEPTION(object);

  while (1)
  {
    xfer += thrift_protocol_read_field_begin (protocol, &fname, &ftype, &fid, error);
    if (ftype == T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == T_STRING) {
          xfer += thrift_protocol_read_string (protocol, &this_object->what, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      case 2:
        if (ftype == T_I32) {
          gint32 ecast0;
          xfer += thrift_protocol_read_i32 (protocol, &ecast0, error);
          this_object->type = (ThriftThrudocExceptionType)ecast0;
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      default:
        xfer += thrift_protocol_skip (protocol, ftype, error);
        break;
    }
    xfer += thrift_protocol_read_field_end (protocol, error);
  }

  xfer += thrift_protocol_read_struct_end (protocol, error);

  return xfer;
}

void thrift_thrudoc_thrudoc_exception_instance_init (ThriftThrudocThrudocException * object)
{
  object->what = "";
}

void thrift_thrudoc_thrudoc_exception_class_init (ThriftStructClass * thrift_struct_class)
{
  thrift_struct_class->write = thrift_thrudoc_thrudoc_exception_write;
}

GType thrift_thrudoc_thrudoc_exception_get_type (void)
{
  static GType type = 0;

  if (type == 0) 
  {
    static const GTypeInfo type_info = 
    {
      sizeof (ThriftThrudocThrudocExceptionClass),
      NULL, /* base_init */
      NULL, /* base_finalize */
      (GClassInitFunc)thrift_thrudoc_thrudoc_exception_class_init,
      NULL, /* class_finalize */
      NULL, /* class_data */
      sizeof (ThriftThrudocThrudocException),
      0, /* n_preallocs */
      (GInstanceInitFunc)thrift_thrudoc_thrudoc_exception_instance_init,
      NULL, /* value_table */
    };

    type = g_type_register_static (THRIFT_TYPE_STRUCT, 
                                   "ThriftThrudocThrudocExceptionType",
                                   &type_info, 0);
  }

  return type;
}

gint32 thrift_thrudoc_element_write (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  ThriftThrudocElement * this_object = THRIFT_THRUDOC_ELEMENT(object);
  xfer += thrift_protocol_write_struct_begin (protocol, "Element", error);
  xfer += thrift_protocol_write_field_begin (protocol, "bucket", T_STRING, 1, error);
  xfer += thrift_protocol_write_string(protocol, this_object->bucket, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_begin (protocol, "key", T_STRING, 2, error);
  xfer += thrift_protocol_write_string(protocol, this_object->key, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_begin (protocol, "value", T_STRING, 3, error);
  xfer += thrift_protocol_write_string(protocol, this_object->value, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_stop(protocol, error);
  xfer += thrift_protocol_write_struct_end(protocol, error);
  return xfer;
}

gint32 thrift_thrudoc_element_read (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  gchar * fname;
  ThriftType ftype;
  gint16 fid;

  xfer += thrift_protocol_read_struct_begin (protocol, &fname, error);
  ThriftThrudocElement * this_object = THRIFT_THRUDOC_ELEMENT(object);

  while (1)
  {
    xfer += thrift_protocol_read_field_begin (protocol, &fname, &ftype, &fid, error);
    if (ftype == T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == T_STRING) {
          xfer += thrift_protocol_read_string (protocol, &this_object->bucket, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      case 2:
        if (ftype == T_STRING) {
          xfer += thrift_protocol_read_string (protocol, &this_object->key, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      case 3:
        if (ftype == T_STRING) {
          xfer += thrift_protocol_read_string (protocol, &this_object->value, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      default:
        xfer += thrift_protocol_skip (protocol, ftype, error);
        break;
    }
    xfer += thrift_protocol_read_field_end (protocol, error);
  }

  xfer += thrift_protocol_read_struct_end (protocol, error);

  return xfer;
}

void thrift_thrudoc_element_instance_init (ThriftThrudocElement * object)
{
  object->bucket = "";
  object->key = "";
  object->value = "";
}

void thrift_thrudoc_element_class_init (ThriftStructClass * thrift_struct_class)
{
  thrift_struct_class->write = thrift_thrudoc_element_write;
}

GType thrift_thrudoc_element_get_type (void)
{
  static GType type = 0;

  if (type == 0) 
  {
    static const GTypeInfo type_info = 
    {
      sizeof (ThriftThrudocElementClass),
      NULL, /* base_init */
      NULL, /* base_finalize */
      (GClassInitFunc)thrift_thrudoc_element_class_init,
      NULL, /* class_finalize */
      NULL, /* class_data */
      sizeof (ThriftThrudocElement),
      0, /* n_preallocs */
      (GInstanceInitFunc)thrift_thrudoc_element_instance_init,
      NULL, /* value_table */
    };

    type = g_type_register_static (THRIFT_TYPE_STRUCT, 
                                   "ThriftThrudocElementType",
                                   &type_info, 0);
  }

  return type;
}

gint32 thrift_thrudoc_scan_response_write (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  ThriftThrudocScanResponse * this_object = THRIFT_THRUDOC_SCAN_RESPONSE(object);
  xfer += thrift_protocol_write_struct_begin (protocol, "ScanResponse", error);
  xfer += thrift_protocol_write_field_begin (protocol, "elements", T_LIST, 1, error);
  {
    xfer += thrift_protocol_write_list_begin(protocol, T_STRUCT, this_object->elements->len, error);
    int i;
    for (i = 0; i < this_object->elements->len; i++)
    {
      xfer += thrift_struct_write (THRIFT_STRUCT (g_ptr_array_index(this_object->elements, i)), protocol, error);
    }
    xfer += thrift_protocol_write_list_end(protocol, error);
  }
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_begin (protocol, "seed", T_STRING, 2, error);
  xfer += thrift_protocol_write_string(protocol, this_object->seed, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_stop(protocol, error);
  xfer += thrift_protocol_write_struct_end(protocol, error);
  return xfer;
}

gint32 thrift_thrudoc_scan_response_read (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  gchar * fname;
  ThriftType ftype;
  gint16 fid;

  xfer += thrift_protocol_read_struct_begin (protocol, &fname, error);
  ThriftThrudocScanResponse * this_object = THRIFT_THRUDOC_SCAN_RESPONSE(object);

  while (1)
  {
    xfer += thrift_protocol_read_field_begin (protocol, &fname, &ftype, &fid, error);
    if (ftype == T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == T_LIST) {
          {
            guint32 _size2;
            ThriftType _etype5;
            thrift_protocol_read_list_begin (protocol, &_etype5, &_size2, error);
            this_object->elements = g_ptr_array_new ();
            guint32 _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              ThriftThrudocElement * _elem7;
              xfer += thrift_struct_read (THRIFT_STRUCT (_elem7), protocol, error);
              g_ptr_array_add (this_object->elements, _elem7);
            }
            thrift_protocol_read_list_end (protocol, error);
          }
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      case 2:
        if (ftype == T_STRING) {
          xfer += thrift_protocol_read_string (protocol, &this_object->seed, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      default:
        xfer += thrift_protocol_skip (protocol, ftype, error);
        break;
    }
    xfer += thrift_protocol_read_field_end (protocol, error);
  }

  xfer += thrift_protocol_read_struct_end (protocol, error);

  return xfer;
}

void thrift_thrudoc_scan_response_instance_init (ThriftThrudocScanResponse * object)
{
  object->seed = "";
}

void thrift_thrudoc_scan_response_class_init (ThriftStructClass * thrift_struct_class)
{
  thrift_struct_class->write = thrift_thrudoc_scan_response_write;
}

GType thrift_thrudoc_scan_response_get_type (void)
{
  static GType type = 0;

  if (type == 0) 
  {
    static const GTypeInfo type_info = 
    {
      sizeof (ThriftThrudocScanResponseClass),
      NULL, /* base_init */
      NULL, /* base_finalize */
      (GClassInitFunc)thrift_thrudoc_scan_response_class_init,
      NULL, /* class_finalize */
      NULL, /* class_data */
      sizeof (ThriftThrudocScanResponse),
      0, /* n_preallocs */
      (GInstanceInitFunc)thrift_thrudoc_scan_response_instance_init,
      NULL, /* value_table */
    };

    type = g_type_register_static (THRIFT_TYPE_STRUCT, 
                                   "ThriftThrudocScanResponseType",
                                   &type_info, 0);
  }

  return type;
}

gint32 thrift_thrudoc_list_response_write (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  ThriftThrudocListResponse * this_object = THRIFT_THRUDOC_LIST_RESPONSE(object);
  xfer += thrift_protocol_write_struct_begin (protocol, "ListResponse", error);
  xfer += thrift_protocol_write_field_begin (protocol, "element", T_STRUCT, 1, error);
  xfer += thrift_struct_write (THRIFT_STRUCT (this_object->element), protocol, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_begin (protocol, "ex", T_STRUCT, 2, error);
  xfer += thrift_struct_write (THRIFT_STRUCT (this_object->ex), protocol, error);
  xfer += thrift_protocol_write_field_end (protocol, error);
  xfer += thrift_protocol_write_field_stop(protocol, error);
  xfer += thrift_protocol_write_struct_end(protocol, error);
  return xfer;
}

gint32 thrift_thrudoc_list_response_read (ThriftStruct * object, ThriftProtocol * protocol, GError ** error)
{
  gint32 xfer = 0;
  gchar * fname;
  ThriftType ftype;
  gint16 fid;

  xfer += thrift_protocol_read_struct_begin (protocol, &fname, error);
  ThriftThrudocListResponse * this_object = THRIFT_THRUDOC_LIST_RESPONSE(object);

  while (1)
  {
    xfer += thrift_protocol_read_field_begin (protocol, &fname, &ftype, &fid, error);
    if (ftype == T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == T_STRUCT) {
          xfer += thrift_struct_read (THRIFT_STRUCT (this_object->element), protocol, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      case 2:
        if (ftype == T_STRUCT) {
          xfer += thrift_struct_read (THRIFT_STRUCT (this_object->ex), protocol, error);
        } else {
          xfer += thrift_protocol_skip (protocol, ftype, error);
        }
        break;
      default:
        xfer += thrift_protocol_skip (protocol, ftype, error);
        break;
    }
    xfer += thrift_protocol_read_field_end (protocol, error);
  }

  xfer += thrift_protocol_read_struct_end (protocol, error);

  return xfer;
}

void thrift_thrudoc_list_response_instance_init (ThriftThrudocListResponse * object)
{
}

void thrift_thrudoc_list_response_class_init (ThriftStructClass * thrift_struct_class)
{
  thrift_struct_class->write = thrift_thrudoc_list_response_write;
}

GType thrift_thrudoc_list_response_get_type (void)
{
  static GType type = 0;

  if (type == 0) 
  {
    static const GTypeInfo type_info = 
    {
      sizeof (ThriftThrudocListResponseClass),
      NULL, /* base_init */
      NULL, /* base_finalize */
      (GClassInitFunc)thrift_thrudoc_list_response_class_init,
      NULL, /* class_finalize */
      NULL, /* class_data */
      sizeof (ThriftThrudocListResponse),
      0, /* n_preallocs */
      (GInstanceInitFunc)thrift_thrudoc_list_response_instance_init,
      NULL, /* value_table */
    };

    type = g_type_register_static (THRIFT_TYPE_STRUCT, 
                                   "ThriftThrudocListResponseType",
                                   &type_info, 0);
  }

  return type;
}

