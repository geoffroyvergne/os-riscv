#!/bin/bash

set -xue

QEMU=qemu-system-riscv32

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot -kernel kernel.elf
