
#ifndef __GPIO__H__
#define __GPIO__H__

/*****************************************************************************                                                                           *
 *                                 includes                                  *                                                     *
 *****************************************************************************/
#include "sys_common.h"

/*****************************************************************************                                                                 *
 *                   Add macros, constants, typedefs here                    *                                                                        *
 *****************************************************************************/
/* GPIO registers */
#define GPIO_BASE     (PERIPH_BASE + 0x200000)

#define GPFSEL0       ((volatile uint32_t *)(GPIO_BASE))
#define GPFSEL1       ((volatile uint32_t *)(GPIO_BASE + 0x04))
#define GPFSEL2       ((volatile uint32_t *)(GPIO_BASE + 0x08))
#define GPFSEL3       ((volatile uint32_t *)(GPIO_BASE + 0x0C))
#define GPFSEL4       ((volatile uint32_t *)(GPIO_BASE + 0x10))
#define GPFSEL5       ((volatile uint32_t *)(GPIO_BASE + 0x14))

#define GPSET0        ((volatile uint32_t*)(GPIO_BASE + 0x1C))
#define GPSET1        ((volatile uint32_t*)(GPIO_BASE + 0x20))

#define GPCLR0        ((volatile uint32_t*)(GPIO_BASE + 0x28))
#define GPCLR1        ((volatile uint32_t*)(GPIO_BASE + 0x2C))

#define GPLEV0        ((volatile uint32_t *)(GPIO_BASE + 0x34))
#define GPLEV1        ((volatile uint32_t *)(GPIO_BASE + 0x38))

#define GPEDS0        ((volatile uint32_t *)(GPIO_BASE + 0x40))
#define GPEDS1        ((volatile uint32_t *)(GPIO_BASE + 0x44))

#define GPREN0        ((volatile uint32_t *)(GPIO_BASE + 0x4C))
#define GPREN1        ((volatile uint32_t *)(GPIO_BASE + 0x50))

#define GPFEN0        ((volatile uint32_t *)(GPIO_BASE + 0x58))
#define GPFEN1        ((volatile uint32_t *)(GPIO_BASE + 0x5C))

#define GPHEN0        ((volatile uint32_t *)(GPIO_BASE + 0x64))
#define GPHEN1        ((volatile uint32_t *)(GPIO_BASE + 0x68))

#define GPLEN0        ((volatile uint32_t *)(GPIO_BASE + 0x70))
#define GPLEN1        ((volatile uint32_t *)(GPIO_BASE + 0x74))

#define GPAREN0       ((volatile uint32_t *)(GPIO_BASE + 0x7C))
#define GPAREN1       ((volatile uint32_t *)(GPIO_BASE + 0x80))

#define GPAFEN0       ((volatile uint32_t *)(GPIO_BASE + 0x88))
#define GPAFEN1       ((volatile uint32_t *)(GPIO_BASE + 0x8C))

#define GPPUD         ((volatile uint32_t *)(GPIO_BASE + 0x94))
#define GPPUDCLK0     ((volatile uint32_t *)(GPIO_BASE + 0x98))
#define GPPUDCLK1     ((volatile uint32_t *)(GPIO_BASE + 0x9C))

/* GPIO PINS */
typedef enum GPIO {
  GPIO0 = 0,
  GPIO1 = 1,
  GPIO2 = 2,
  GPIO3 = 3,
  GPIO4 = 4,
  GPIO5 = 5,
  GPIO6 = 6,
  GPIO7 = 7,
  GPIO8 = 8,
  GPIO9 = 9,
  GPIO10 = 10,
  GPIO11 = 11,
  GPIO12 = 12,
  GPIO13 = 13,
  GPIO14 = 14,
  GPIO15 = 15,
  GPIO16 = 16,
  GPIO17 = 17,
  GPIO18 = 18,
  GPIO19 = 19,
  GPIO20 = 20,
  GPIO21 = 21,
  GPIO22 = 22,
  GPIO23 = 23,
  GPIO24 = 24,
  GPIO25 = 25,
  GPIO26 = 26,
  GPIO27 = 27,
  GPIO28 = 28,
  GPIO29 = 29,
  GPIO30 = 30,
  GPIO31 = 31,
  GPIO32 = 32,
  GPIO33 = 33,
  GPIO34 = 34,
  GPIO35 = 35,
  GPIO36 = 36,
  GPIO37 = 37,
  GPIO38 = 38,
  GPIO39 = 39,
  GPIO40 = 40,
  GPIO41 = 41,
  GPIO42 = 42,
  GPIO43 = 43,
  GPIO44 = 44,
  GPIO45 = 45,
  GPIO46 = 46,
  GPIO47 = 47,
  GPIO48 = 48,
  GPIO49 = 49,
  GPIO50 = 50,
  GPIO51 = 51,
  GPIO52 = 52,
  GPIO53 = 53
} gpio;

typedef enum ioconfig {
  INPUT  = 0,
  OUTPUT = 1
} iocfg;

// #define GPIO0_SEL     (7 << 0) & *GPFSEL0
// #define GPIO1_SEL     (7 << 3) & *GPFSEL0 
// #define GPIO2_SEL     (7 << 6) & *GPFSEL0
// #define GPIO3_SEL     (7 << 9) & *GPFSEL0
// #define GPIO4_SEL     (7 << 12) & 0xFFFFFFFF
// #define GPIO5_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO6_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO7_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO8_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO9_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO10_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO11_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO12_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO13_SEL     (7 << 15) & 0xFFFFFFFF
// #define GPIO14_SEL     (7 << 15) & 0xFFFFFFFF


/*****************************************************************************                                                                       *
 *                           function prototypes                             *                                                                    *
 *****************************************************************************/

void init_gpio(gpio pin, iocfg type);
void set_gpio(gpio pin);
void clear_gpio(gpio pin);
void toggle_gpio(gpio pin);
void init_gpios(gpio pins[], iocfg types[], uint32_t nr);
void set_pins(gpio *pins, uint32_t nr);
void clear_pins(gpio *pins, uint32_t nr);

#endif /* gpio.h */
