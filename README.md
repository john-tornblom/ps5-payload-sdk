# PS5 Payload SDK
This is an SDK for developing ELF payloads targeted at exploited PS5s, running
the [BD-J ELF loader][bjd-elf] or the [Webkit ELF loader][webkit-elf].

## Prerequisites
In order to generate trampolines for essential system libraries on the PS5, you
need to obtain sprx files from your PS5 console. Decrypt the sprx files your
payload is suppose to interact with, and place them (with the same filename as
used on the PS5) in the root directory of this repository. You also need a build
environment. On Debian-flavored operating systems, you can invoke the following
command to install dependencies used by the SDK.
```console
john@localhost:ps5-payload-sdk$ sudo apt-get install wget clang python3 python3-pyelftools
```

## Building
```console
john@localhost:ps5-payload-sdk$ make
```

## Installation
```console
john@localhost:ps5-payload-sdk$ make DESTDIR=/opt/ps5-payload-sdk install
```

## Usage
```console
john@localhost:ps5-payload-sdk$ export PS5_PAYLOAD_SDK=/opt/ps5-payload-sdk
john@localhost:ps5-payload-sdk$ make -C samples/hello_world
john@localhost:ps5-payload-sdk$ export PS5_HOST=ps5; export PS5_PORT=9020
john@localhost:ps5-payload-sdk$ make -C samples/hello_world test
```

## Reporting Bugs
If you encounter problems with ps5-payload-sdk, please [file a github issue][issues].
If you plan on sending pull requests which affect more than a few lines of code,
please file an issue before you start to work on you changes. This will allow us
to discuss the solution properly before you commit time and effort.

## License
Files in the include_bsd directory are licenced under BSD licences. The files
crt1.c, Makefile, and trampgen.py are licensed under the GPLv3+. The file
linker.x is copied from [PS5SDK][PS5SDK], which is licensed under the GPLv2.

[issues]: https://github.com/john-tornblom/ps5-payload-sdk/issues/new
[bjd-elf]: https://github.com/john-tornblom/bdj-sdk/tree/master/samples/ps5-elf-loader
[webkit-elf]: https://github.com/Cryptogenic/PS5-IPV6-Kernel-Exploit
[PS5SDK]: https://github.com/PS5Dev/PS5SDK
