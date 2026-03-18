#include <stdint.h>

#define PERIPH_BASE   0x3F000000UL
#define GPIO_BASE     (PERIPH_BASE + 0x200000)

#define GPFSEL4       ((volatile uint32_t*)(GPIO_BASE + 0x10))
#define GPSET1        ((volatile uint32_t*)(GPIO_BASE + 0x20))
#define GPCLR1        ((volatile uint32_t*)(GPIO_BASE + 0x2C))

static void delay(int32_t count) {
    while (count--) {
        __asm__ volatile("nop");
    }
}

void main(void) {
    /* GPIO47 as output (ACT LED on many Pi 2 revisions) */
    uint32_t ra = *GPFSEL4;
    ra &= ~(7 << 21);
    ra |=  (1 << 21);
    *GPFSEL4 = ra;

    while (1) {
        *GPSET1 = (1 << 15);  /* GPIO47 high */
        delay(1000000);
        *GPCLR1 = (1 << 15);  /* GPIO47 low */
        delay(500000);
    }
}