# PeachOS

A simple operating system for learning purposes.

## Setup (Ubuntu)

follow the instructions here: https://wiki.osdev.org/GCC_Cross-Compiler

## Setup (M1 Mac)

```bash
brew install qemu
brew install nasm
brew install i686-elf-binutils i686-elf-gcc
```

## Build

```bash
./build.sh
```

## Run

```bash
qemu-system-i386 -hda ./bin/os.bin
```

## Debug

start gdb

```bash
gdb
```

set target and breakpoint

```
add-symbol-file ./build/kernelfull.o 0x100000
break _start
remote target | qemu-system-i386 -S -gdb stdio -hda ./bin/os.bin
```

## Debug (using lldb)

start qemu with gdb server

```bash
qemu-system-i386 -S -s -hda ./bin/os.bin
```

start lldb

```bash
lldb
```

set target and breakpoint

```
target create ./build/kernelfull.o
breakpoint set --name kernel_main
gdb-remote localhost:1234
```

## Clean

```bash
make clean
```

# References

https://github.com/nibblebits/PeachOS
