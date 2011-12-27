# libthai4r

Ruby Libthai binding for Ruby 1.9.x.

Original progect http://code.google.com/p/libthai4r

## Install

### libdatrie

	$ wget ftp://linux.thai.net/pub/thailinux/software/libthai/libdatrie-0.2.4.tar.gz
	$ tar zxvf libdatrie-0.2.4
	$ cd libdatrie-0.2.4
	$ ./configure
	$ make
	$ sudo make install

### libthai

	$ wget http://linux.thai.net/pub/thailinux/software/libthai/libthai-0.1.16.tar.gz
	$ tar zxvf libthai-0.1.16.tar.gz 
	$ cd libthai-0.1.16/
	$ ./configure 
	$ make
	$ sudo make install

### ruby-libthai

	$ mkdir libthai4r && curl -L https://github.com/neokain/libthai4r/zipball/master | tar xz --strip 1 -C libthai4r
	$ cd libthai4r
	$ sudo ruby extconf.rb
	$ make
	$ sudo make install

In command *$ make* if you found error like this (I found this problem when compile in Linux)

	./libthai.so: file not recognized: File truncated

That mean the make can't compile output is **libthai.so**

You can fix this problem with edit **Makefile** to complie in another name extension

	DLLIB = $(TARGET).so --> DLLIB = $(TARGET).sox

and

	CLEANLIBS     = $(TARGET).so --> CLEANLIBS     = $(TARGET).sox

atfer that change file name extension that compile finish

	$ mv libthai.sox libthai.so

and can *$ sudo make install*. You can test with test file in test folder.

## Usage

You much install iconv. If You using RMV you can do follow this http://beginrescueend.com/packages/iconv

	#!/usr/bin/env ruby
	# encoding: utf-8

	require "iconv"
	require 'libthai'

	utf8_to_tis620 = Iconv.new("TIS620", "UTF-8")
	a = LibThai::brk_line(utf8_to_tis620.iconv("ภาษาไทยเป็นภาษาที่ง่ายที่สุดในโลก"))

	tis620_to_utf8 = Iconv.new("UTF-8", "TIS620")
	o = tis620_to_utf8.iconv(a)

	print o

Result

	ภาษา|ไทย|เป็น|ภาษา|ที่|ง่าย|ที่สุด|ใน|โลก

## License

Copyright © 2011 Phuwanart Larpmark, released under the MIT license