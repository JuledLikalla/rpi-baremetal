#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include "uart.h"

// extern void uart_putc(char c);

/* Provided by the linker script */
extern char end;
extern char _end;

int _write(int file, const char *ptr, int len)
{
    (void)file;

    for (int i = 0; i < len; i++) {
        if (ptr[i] == '\n') {
            uart_putc('\r');
        }
        uart_putc(ptr[i]);
    }

    return len;
}

int _read(int file, char *ptr, int len)
{
    (void)file;
    (void)ptr;
    (void)len;
    errno = ENOSYS;
    return -1;
}

int _close(int file)
{
    (void)file;
    errno = ENOSYS;
    return -1;
}

int _fstat(int file, struct stat *st)
{
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file)
{
    (void)file;
    return 1;
}

int _lseek(int file, int ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

void *_sbrk(ptrdiff_t incr)
{
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == NULL) {
        heap_end = &_end;
    }

    prev_heap_end = heap_end;
    heap_end += incr;

    return prev_heap_end;
}