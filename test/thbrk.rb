#!/usr/bin/env ruby

require 'iconv'
require 'libthai'

utf8_to_tis620 = Iconv.new('TIS620', 'UTF-8')

a = LibThai.brk_line(utf8_to_tis620.iconv('ภาษาไทยเป็นภาษาที่ง่ายที่สุดในโลก'))

tis620_to_utf8 = Iconv.new('UTF-8', 'TIS620')

o = tis620_to_utf8.iconv(a)

puts o
