#include "uart.h"

void uart_init(void)
{
    /* 1) Disable UART0 */
    *UART0_CR = 0x00000000;

    /* 2) Set GPIO14 and GPIO15 to ALT0 (TXD0/RXD0) */
    uint32_t ra = *GPFSEL1;
    ra &= ~((7 << 12) | (7 << 15));  /* clear FSEL14, FSEL15 */
    ra |=  (4 << 12) | (4 << 15);    /* ALT0 = 100 */
    *GPFSEL1 = ra;

    /* 3) Disable pull-up/down for pins 14 and 15 */
    *GPPUD = 0x00000000;
    delay(150);
    *GPPUDCLK0 = (1 << 14) | (1 << 15);
    delay(150);
    *GPPUDCLK0 = 0x00000000;

    /* 4) Clear pending interrupts */
    *UART0_ICR = 0x7FF;

    /*
     * 5) Baud rate = 115200
     *
     * Assumes UART reference clock = 48 MHz
     * Divider = 48,000,000 / (16 * 115200) = 26.041666...
     * IBRD = 26
     * FBRD = int(0.041666 * 64 + 0.5) = 3
     */
    *UART0_IBRD = 26;
    *UART0_FBRD = 3;

    /* 6) 8 bits, no parity, 1 stop bit, FIFO enabled */
    *UART0_LCRH = (1 << 4) | (3 << 5);   /* FEN + WLEN=8 */

    /* 7) Mask all interrupts */
    *UART0_IMSC = 0x00000000;

    /* 8) Enable UART, TX, RX */
    *UART0_CR = (1 << 0) | (1 << 8) | (1 << 9);
}

void uart_putc(char c)
{
    while (*UART0_FR & (1 << 5)) {
        /* wait while TXFF set */
    }
    *UART0_DR = (uint32_t)c;
}

void uart_puts(const char *s)
{
    while (*s) {
        if (*s == '\n')
            uart_putc('\r');
        uart_putc(*s++);
    }
}