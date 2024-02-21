# PeachOS

## Build

```bash
./build.sh
```

## Run

```bash
qemu-system-i386 -hda ./bin/os.bin
```

## Debug

```bash
gdb
```

```
add-symbol-file ./build/kernelfull.o 0x100000
break _start
remote target | qemu-system-i386 -S -gdb stdio -hda ./bin/os.bin
```

# References

https://github.com/nibblebits/PeachOS
