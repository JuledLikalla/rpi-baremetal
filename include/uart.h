
#ifndef __UART__H__
#define __UART__H__

/*****************************************************************************                                                                           *
 *                                 includes                                  *                                                     *
 *****************************************************************************/
#include "sys_common.h"
#include "gpio.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>

/*****************************************************************************                                                                 *
 *                   Add macros, constants, typedefs here                    *                                                                        *
 *****************************************************************************/
#define UART0_BASE    (PERIPH_BASE + 0x201000)

/* PL011 UART registers */
#define UART0_FR      ((volatile uint32_t *)(UART0_BASE + 0x18))
#define UART0_DR      ((volatile uint32_t *)(UART0_BASE + 0x00))
#define UART0_IBRD    ((volatile uint32_t *)(UART0_BASE + 0x24))
#define UART0_FBRD    ((volatile uint32_t *)(UART0_BASE + 0x28))
#define UART0_LCRH    ((volatile uint32_t *)(UART0_BASE + 0x2C))
#define UART0_CR      ((volatile uint32_t *)(UART0_BASE + 0x30))
#define UART0_IMSC    ((volatile uint32_t *)(UART0_BASE + 0x38))
#define UART0_ICR     ((volatile uint32_t *)(UART0_BASE + 0x44))


/*****************************************************************************                                                                       *
 *                           function prototypes                             *                                                                    *
 *****************************************************************************/

void uart_init(void);
void uart_putc(char c);
void uart_puts(const char *s);

#endif /* uart.h */
