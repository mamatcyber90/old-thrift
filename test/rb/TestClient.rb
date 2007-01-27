#!/usr/bin/ruby

$:.push('gen-rb')
$:.push('../../lib/ruby/lib')

require 'thrift/transport/tsocket'
require 'thrift/protocol/tbinaryprotocol'
require 'ThriftTest'

s = TSocket.new('localhost', 9090)
p = TBinaryProtocol.new(s)
c = ThriftTest::Client.new(p)

s.open()

puts c.testString('string')
puts c.testByte(8)
puts c.testByte(-8)
puts c.testI32(32)
puts c.testI32(-32)
puts c.testI64(64)
puts c.testI64(-64)
puts c.testDouble(3.14)
puts c.testDouble(-3.14)
puts c.testMap({1 => 1, 2 => 2, 3 => 3})
puts c.testList([1,2,3,4,5])
puts c.testSet({1 => true, 2 => true, 3 => true})

s.close()


