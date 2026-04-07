ENTRY(_start)

SECTIONS
{
    . = 0x8000;
    __start = .;
    .text : {
      KEEP(*(.text.boot))
      *(.text*)
    }
    . = ALIGN(4096);
    .rodata : {
      *(.rodata*)
    }
    . = ALIGN(4096);
    .data : {
        *(.data*)
    }
    . = ALIGN(4096);
    __bss_start__ = .;
    .bss : {
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    }
    . = ALIGN(4096);
    __bss_end__ = .;
    __bss_size = __bss_end__ - __bss_start__;
    end = .;
    _end = .;
    
    . += 0x4000;      /* 16 KB stack */
    _stack_top = .;
}