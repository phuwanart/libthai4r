# libthai4r

Ruby Libthai binding for Ruby.

Original project http://code.google.com/p/libthai4r

## Install

### libdatrie

```bash
$ wget ftp://linux.thai.net/pub/thailinux/software/libthai/libdatrie-0.2.4.tar.gz
$ tar zxvf libdatrie-0.2.4.tar.gz
$ cd libdatrie-0.2.4
$ ./configure
$ make
$ sudo make install
```

### libthai

```bash
$ wget http://linux.thai.net/pub/thailinux/software/libthai/libthai-0.1.16.tar.gz
$ tar zxvf libthai-0.1.16.tar.gz
$ cd libthai-0.1.16/
$ ./configure
$ make
$ sudo make install
```

### ruby-libthai

```bash
$ mkdir libthai4r && curl -L https://github.com/neokain/libthai4r/tarball/master | tar xz --strip 1 -C libthai4r
$ cd libthai4r
$ ruby extconf.rb
$ make
$ sudo make install
```

In command *$ make* if you found error like this (I found this problem when compile in Linux)

```bash
$ make
./libthai.so: file not recognized: File truncated
collect2: ld returned 1 exit status
make: *** [libthai.so] Error 1
```

Because can't make `libthai.so`. The way of fix it you mush modify `Makfile`.

Find 2 line in `Makefile`

```
LLIB = $(TARGET).so
```
and

```
CLEANLIBS     = $(TARGET).so
```

Change extension name form `.so` to `.sox`. Then run `$ make` again. You must have `libthai.sox`.

Run `$ sudo make install`. You have message like this:

```bash
usr/bin/install -c -m 0755 libthai.sox /home/phuwanart/.rvm/rubies/ruby-2.0.0-p195/lib/ruby/site_ruby/2.0.0/i686-linux
installing default libthai libraries
```

atfer that goto `/home/phuwanart/.rvm/rubies/ruby-2.0.0-p195/lib/ruby/site_ruby/2.0.0/i686-linux` and change file name extension back to `.so`:

```bash
$ mv libthai.sox libthai.so
```

You can test with test file in test folder of source:

```bash
$ ruby test/thbrk.rb
ภาษา|ไทย|เป็น|ภาษา|ที่|ง่าย|ที่สุด|ใน|โลก
```

## Usage

You much install iconv if You using RMV.

```bash
$ gem install iconv
```

Example:

```ruby
#!/usr/bin/env ruby
# encoding: utf-8

require "iconv"
require 'libthai'

utf8_to_tis620 = Iconv.new("TIS620", "UTF-8")
a = LibThai::brk_line(utf8_to_tis620.iconv("ภาษาไทยเป็นภาษาที่ง่ายที่สุดในโลก"))

tis620_to_utf8 = Iconv.new("UTF-8", "TIS620")
o = tis620_to_utf8.iconv(a)

print o
```

Result:

```bash
ภาษา|ไทย|เป็น|ภาษา|ที่|ง่าย|ที่สุด|ใน|โลก
```

## License

Copyright © 2013 Phuwanart Larpmark, released under the MIT license