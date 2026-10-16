#ifndef BITS_H
#define BITS_H

#include <stddef.h>
#include <stdint.h>

unsigned char bit_left_shift(unsigned char value, int shift);
unsigned char bit_right_shift(unsigned char value, int shift);
unsigned char bit_extract(unsigned char value, unsigned char mask);
unsigned char bit_xor(unsigned char a, unsigned char b);

#endif
