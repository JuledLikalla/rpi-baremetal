#include <stdint.h>
#include "sys_common.h"
#include "gpio.h"
#include "uart.h"
#include "led_display.h"

// typedef enum {
//   GP0,
//   GP1,
//   GP5,
//   GP6,
//   GP12,
//   GP13,
//   GP19
// } state;

void main(void) {
    /* GPIO47 as output (ACT LED on many Pi 2 revisions) */
    uart_init();
    printf(">>>>>> RPI Baremetal <<<<<<\n");
    // uint32_t r47 = *GPFSEL4;
    // uint32_t r20 = *GPFSEL2;
    
    // r47 &= ~(7 << 21);
    // r47 |=  (1 << 21);
    // r20 &= ~(7 << 0);
    // r20 |=  (1 << 0);

    
    /*
      A Segment -> GPIO0
      B Segment -> GPIO1
      C Segment -> GPIO5
      D Segment -> GPIO6
      E Segment -> GPIO12
      F Segment -> GPIO13
      G Segment -> GPIO19
    */

    // gpio gpios[7] = { GPIO0, GPIO1, GPIO5, GPIO6, GPIO12, GPIO13, GPIO19 };
    // iocfg types[7]       = { OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT};
    // gpio two[5] = { GPIO0, GPIO1, GPIO6, GPIO12, GPIO19 };
    // init_gpio(GPIO0, OUTPUT);
    // init_gpio(GPIO1, OUTPUT);
    // init_gpio(GPIO5, OUTPUT);
    // init_gpio(GPIO6, OUTPUT);
    // init_gpio(GPIO12, OUTPUT);
    // init_gpio(GPIO13, OUTPUT);
    // init_gpio(GPIO19, OUTPUT);

    // clear_gpio(GPIO0);
    // clear_gpio(GPIO1);
    // clear_gpio(GPIO5);
    // clear_gpio(GPIO6);
    // clear_gpio(GPIO12);
    // clear_gpio(GPIO13);
    // clear_gpio(GPIO19);

    // init_gpios(gpios, types, nrOfSegments);

    init_display();
    // *GPFSEL4 = r47; 
    // *GPFSEL2 = r20;
    // state segState = GP0;
    uint8_t count = 0; 
    printf("count: \n\b");
    while (1) {

        // printf("segState: %d\n", segState);
        // switch(segState) {
        //   case GP0:
        //     toggle_gpio(GPIO0);
        //     break;
        //   case GP1:
        //     toggle_gpio(GPIO1);
        //     break;
        //   case GP5:
        //     toggle_gpio(GPIO5);
        //     break;
        //   case GP6:
        //     toggle_gpio(GPIO6);
        //     break;
        //   case GP12:
        //     toggle_gpio(GPIO12);
        //     break;
        //   case GP13:
        //     toggle_gpio(GPIO13);
        //     break;
        //   case GP19:
        //     toggle_gpio(GPIO19);
        //     break;
        // }
        // segState = (segState + 1) % 7;     
        printNr(count);
        printf("%u\b\n\b", count);
        count = (count + 1) % 10;
        delay(700000000);
        // clear_pins(two, 5);
        // delay(700000000);   
    }
}