#define SET_BIT(__register, __bit) (__register |= __bit)
#define UNSET_BIT(__register, __bit) (__register &= ~__bit)
#define TOGGLE_BIT(__register, __bit) (__register ^= __bit)