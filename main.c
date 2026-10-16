#include "bits.h"

#include <stdio.h>

int main(void)
{
    unsigned char value = 0xAB;  // 10101011

    unsigned char left = bit_left_shift(value, 4);
    unsigned char right = bit_right_shift(value, 4);
    unsigned char low_nibble = bit_extract(value, 0x0F);
    unsigned char high_nibble = bit_extract(bit_right_shift(value, 4), 0x0F);
    unsigned char key = 0x5A;
    unsigned char encrypted = bit_xor(value, key);
    unsigned char decrypted = bit_xor(encrypted, key);

    printf("value:        0x%02X\n", value);
    printf("left shift:   0x%02X\n", left);
    printf("right shift:  0x%02X\n", right);
    printf("low nibble:   0x%02X\n", low_nibble);
    printf("high nibble:  0x%02X\n", high_nibble);
    printf("key:          0x%02X\n", key);
    printf("encrypted:    0x%02X\n", encrypted);
    printf("decrypted:    0x%02X\n", decrypted);

    return 0;
}
