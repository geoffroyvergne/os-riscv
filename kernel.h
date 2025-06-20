#pragma once
#include "common.h"

#define PROCS_MAX 8     // Maximum number of process

#define PROC_UNUSED 0   // Unused process control structure
#define PROC_RUNNABLE 1 // Runnable process

struct process {
    int pid;                // Process ID
    int state;              // Process state: PROC_UNUSED or PROC_RUNNABLE
    vaddr_t sp;             // stack pointer
    uint32_t *page_table;
    uint8_t stack[8192];    // Kernel stack
};

#define PANIC(fmt, ...)                                                        \
    do {                                                                       \
        printf("PANIC: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);  \
        while (1) {}                                                           \
    } while (0)

struct sbiret {
    long error;
    long value;
};

#define SATP_SV32 (1u << 31)
#define PAGE_V    (1 << 0)   // "Valid" bit (entry is enabled)
#define PAGE_R    (1 << 1)   // Readable
#define PAGE_W    (1 << 2)   // Writable
#define PAGE_X    (1 << 3)   // Executable
#define PAGE_U    (1 << 4)   // User (accessible in user mode)

// The base virtual address of an application image. This needs to match the
// starting address defined in `user.ld`.
#define USER_BASE 0x1000000

#define SSTATUS_SPIE (1 << 5)
#define SCAUSE_ECALL 8
#define PROC_EXITED   2
