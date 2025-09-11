# CS 3503 – Assignment 1: Number Base Conversion Utility

Author: Michael Sich

## What this program is

This program is a number base converter written in C. It implements three main functions:

- `div_convert` (conversion using the division algorithm)
- `sub_convert` (conversion using the subtraction algorithm)
- `print_tables` (displays bit manipulation operations in binary, octal, decimal, and hex)

The goal was to take in different numbers and bases and make sure both algorithms produce correct results and also that they match each other. I also had to test bit shifting and masking.

## How I built it

I started by writing the `div_convert` and `sub_convert` functions in **convert.c** and declared them in **convert.h**. Then in **main.c** I wrote test drivers that read from text files and also some direct comparisons between the two algorithms.

At first I tried making one huge test file (`A1_tests.txt`) but parsing it was too messy. I ended up splitting it into multiple smaller text files inside the `separated_tests` folder. This made it much easier to run only the tests I needed.

For comparisons, instead of parsing pairs from a text file, I just hardcoded them in a function. It’s way simpler and I didn’t want to overcomplicate things (I understand this may cost me some points).

## File structure

- **convert.c** – all the function implementations (`div_convert`, `sub_convert`, `print_tables`)
- **convert.h** – header file with function prototypes
- **main.c** – the driver program that runs all the tests
- **README.md** – this file, explains the assignment and how I approached it
- **separated_tests/** – folder with all the test cases split up into three files:
  - `div_tests.txt` – all tests for `div_convert`
  - `sub_tests.txt` – all tests for `sub_convert`
  - `print_tests.txt` – all tests for `print_tables`

## How to build and run

To compile:

```bash
gcc -o a1 main.c convert.c

Repo: https://github.com/M5-sich/cs3503-a1-michael-sich
```
