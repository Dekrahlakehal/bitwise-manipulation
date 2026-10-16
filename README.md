# Bitwise and Crypto Primitives

A small C learning project focused on low-level binary manipulation.

This module demonstrates how raw bytes can be manipulated at the bit level using:

- bit shifting
- masking
- XOR operations

These are foundational concepts in:

- network packet parsing
- binary protocol handling
- simple symmetric encryption
- cryptographic primitive design

---

## Project Goal

The goal of this project is to build a simple toolkit that operates directly on individual bits and bytes instead of treating data as plain text.

This is important because real systems often pack multiple values into a single byte or word. To read or modify those values correctly, we must manipulate the bits directly.

---

## Core Concepts

### 1) Bit Shifting

Bit shifting moves bits left or right to align fields into the correct position.

```c
unsigned char value = 0x05;   // 00000101
unsigned char shifted = value << 4; // 01010000
```

This is useful when you need to move a value into a specific bit range.

### 2) Bit Masking

Masking uses a bitwise AND (`&`) to keep only the bits you care about.

```c
unsigned char value = 0xAB; // 10101011
unsigned char mask = 0x0F; // 00001111
unsigned char low_nibble = value & mask;
```

This isolates the lower 4 bits.

### 3) XOR

XOR (`^`) flips bits only when they differ.

```c
unsigned char cipher = plain ^ key;
unsigned char recovered = cipher ^ key;
```

This is the core property behind simple symmetric encryption and many basic cryptographic ideas.

---

## Files

- `bits.h` — public function declarations
- `bits.c` — implementation of the bitwise operations
- `main.c` — demonstration and test driver

---

## API

```c
unsigned char bit_left_shift(unsigned char value, int shift);
unsigned char bit_right_shift(unsigned char value, int shift);
unsigned char bit_extract(unsigned char value, unsigned char mask);
unsigned char bit_xor(unsigned char a, unsigned char b);
```

---

## Example Usage

```c
unsigned char value = 0xAB;
unsigned char low_nibble = bit_extract(value, 0x0F);
unsigned char high_nibble = bit_extract(bit_right_shift(value, 4), 0x0F);
unsigned char encrypted = bit_xor(value, 0x5A);
```

---

## Compile and Run

From the project directory:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c bits.c -o bit_demo
./bit_demo
```

---

## What the Demo Prints

The program demonstrates:

- the original byte value
- left shift result
- right shift result
- low nibble extraction
- high nibble extraction
- XOR encryption
- XOR decryption

This helps confirm that the primitive operations behave correctly.

---

## Why This Matters

These operations are used in many real-world systems:

- network header parsing
- bit flags and masks
- binary serialization
- simple crypto primitives
- low-level protocol implementations

---

## Notes

This project is intentionally minimal and educational.

It is designed to make the logic behind bit operations and byte-level manipulation easy to understand before moving into more advanced cryptographic work.
