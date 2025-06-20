#!/bin/bash

set -xue

QEMU=qemu-system-riscv32

# Start QEMU
#$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot -kernel kernel.elf

$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -d unimp,guest_errors,int,cpu_reset -D qemu.log \
    -drive id=drive0,file=lorem.txt,format=raw,if=none \
    -device virtio-blk-device,drive=drive0,bus=virtio-mmio-bus.0 \
    -kernel kernel.elf
