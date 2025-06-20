# OS from scratch RISC-V

https://operating-system-in-1000-lines.vercel.app/en/
https://github.com/nuta/operating-system-in-1000-lines

# qemu console
ctrl+a h (help)
ctrl+a c (debug)
clrl+a x (quit)

# qemu debug (ctrl+a c)
stop
info registers
info mem

# debug qemu option
-d unimp,guest_errors,int,cpu_reset -D qemu.log

# dump kernel info (debug)
/opt/homebrew/opt/llvm/bin/llvm-objdump -d kernel.elf

# check address functions (debug)
/opt/homebrew/opt/llvm/bin/llvm-nm kernel.elf 
/opt/homebrew/opt/llvm/bin/llvm-nm shell.bin.o 

/opt/homebrew/opt/llvm/bin/llvm-addr2line -e kernel.elf 802000ca