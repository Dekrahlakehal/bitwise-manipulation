#include "bits.h"

unsigned char bit_left_shift(unsigned char value, int shift)
{
    if (shift < 0) {
        return bit_right_shift(value, -shift);
    }

    return (unsigned char)(value << shift);
}

unsigned char bit_right_shift(unsigned char value, int shift)
{
    if (shift < 0) {
        return bit_left_shift(value, -shift);
    }

    return (unsigned char)(value >> shift);
}

unsigned char bit_extract(unsigned char value, unsigned char mask)
{
    return (unsigned char)(value & mask);
}

unsigned char bit_xor(unsigned char a, unsigned char b)
{
    return (unsigned char)(a ^ b);
}
