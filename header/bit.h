#pragma once

#include<msp430.h>


#define SET_BIT(__register, __bit) (__register |= __bit)
#define UNSET_BIT(__register, __bit) (__register &= ~__bit)
#define TOGGLE_BIT(__register, __bit) (__register ^= __bit)

#define LED (BIT0 | BIT6)
