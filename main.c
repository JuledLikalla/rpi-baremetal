#include <stdint.h>

#define PERIPH_BASE   0x3F000000UL
#define GPIO_BASE     (PERIPH_BASE + 0x200000)

#define GPFSEL2       ((volatile uint32_t*)(GPIO_BASE + 0x8))
#define GPSET0        ((volatile uint32_t*)(GPIO_BASE + 0x1C))
#define GPCLR0        ((volatile uint32_t*)(GPIO_BASE + 0x28))

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
    // uint32_t r47 = *GPFSEL4;
    uint32_t r20 = *GPFSEL2;
    // r47 &= ~(7 << 21);
    // r47 |=  (1 << 21);
    r20 &= ~(7 << 0);
    r20 |=  (1 << 0);

    // *GPFSEL4 = r47;
    *GPFSEL2 = r20;



    while (1) {
        // *GPSET1 = (1 << 15);  /* GPIO47 high */
        *GPSET0 = (1 << 20);  /* GPIO47 high */
        delay(1000000);
        // *GPCLR1 = (1 << 15);  /* GPIO47 low */
        *GPCLR0 = (1 << 20);  /* GPIO47 low */
        delay(500000);
    }
}