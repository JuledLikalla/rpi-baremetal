#include "gpio.h"
#include "uart.h"

volatile uint32_t *getGPIOReg(uint32_t gpgroup) {

  /* code */
  switch (gpgroup)
  {
    case 0:
      return GPFSEL0;
    case 1:
      return GPFSEL1;
    case 2:
      return GPFSEL2;
    case 3:
      return GPFSEL3;
    case 4:
      return GPFSEL4;
    // default:
    //   break;
  };

  return GPFSEL5;
}

void init_gpio(gpio pin, iocfg type) {
  uint32_t gpgroup = (uint32_t)pin / 10;
  uint32_t shift = ((uint32_t)pin % 10) * 3;

  volatile uint32_t *reg = NULL;
  uint32_t regVal = 0;

  reg = getGPIOReg(gpgroup);

  regVal  = *reg;
  regVal &= ~(7 << shift);
  regVal |= (type << shift);
  *reg    = regVal;

  if (type == OUTPUT) {
    clear_gpio(pin);
  }
}

void set_gpio(gpio pin) { 

  if (pin < GPIO32) {
    *GPSET0 = (1 << pin);
    return;
  }

  *GPSET1 = (1 << (pin - 32));
}

void clear_gpio(gpio pin) {

  if (pin < GPIO32) {
    *GPCLR0  = (1 << pin);
    return;
  }

  *GPCLR1  = (1 << (pin - 32));
}

void toggle_gpio(gpio pin) { 
  volatile uint32_t *reg = NULL;
  uint32_t shift = pin;
  if (pin < GPIO32) {
    reg = GPLEV0;
  } else {
    reg = GPLEV1;
    shift = (pin - 32);
  }

  if ((*reg & (1 << shift)) == (uint32_t)(1 << shift)) {
    clear_gpio(pin);
    return;
  }
  
  set_gpio(pin);
}

void init_gpios(gpio pins[], iocfg types[], uint32_t nr) {
  uint32_t gpgroup = 0;
  uint32_t shift   = 0;

  volatile uint32_t *reg = NULL;
  uint32_t regVal = 0;

  for (uint32_t it = 0; it < nr; it++) {
    gpgroup = (uint32_t)pins[it] / 10;
    shift = ((uint32_t)pins[it] % 10) * 3;

    reg = getGPIOReg(gpgroup);

    regVal  = *reg;
    regVal &= ~(7 << shift);
    regVal |= (types[it] << shift);
    *reg    = regVal;

    if (types[it] == OUTPUT) {
      clear_gpio(pins[it]);
    }
  }

}

void set_pins(gpio *pins, uint32_t nr) {
  uint32_t regVal0 = 0;
  uint32_t regVal1 = 0;

  for (uint32_t it = 0; it < nr; it++) {
    if (pins[it] < GPIO32) {
      regVal0 |= (1 << pins[it]);
    }
    else {
      regVal1 |= (1 << (pins[it] - 32));
    }
  }

  if (regVal0 > 0)
    *GPSET0 = regVal0;
  if (regVal1 > 0)
    *GPSET1 = regVal1;
}

void clear_pins(gpio *pins, uint32_t nr) {
  uint32_t regVal0 = 0;
  uint32_t regVal1 = 0;

  for (uint32_t it = 0; it < nr; it++) {
    if (pins[it] < GPIO32) {
      regVal0 |= (1 << pins[it]);
    }
    else {
      regVal1 |= (1 << (pins[it] - 32));
    }
  }

  if (regVal0 > 0)
    *GPCLR0 = regVal0;
  if (regVal1 > 0)
    *GPCLR1 = regVal1;
}
