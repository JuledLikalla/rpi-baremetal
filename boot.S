.syntax unified
.cpu cortex-a7
.fpu vfpv3
.section .text.boot

.global _start
_start:
    /* Read MPIDR to identify core */
    mrc p15, 0, r0, c0, c0, 5
    and r0, r0, #3
    cmp r0, #0
    bne hang

    /* Set up stack */
    ldr sp, =_stack_top

    /* Zero BSS */
    ldr r0, =__bss_start__
    ldr r1, =__bss_end__
1:
    cmp r0, r1
    bge 2f
    mov r2, #0
    str r2, [r0], #4
    b 1b
2:
    bl main

hang:
    wfe
    b hang