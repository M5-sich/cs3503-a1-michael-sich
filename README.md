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

## what to expect when running

when you run `./a1` the program shows a menu like this:
menu: 1. run division tests 2. run subtraction tests 3. run comparison tests 4. run print_tables tests 5. convert any number

## File structure

- **convert.c** – all the function implementations (`div_convert`, `sub_convert`, `print_tables`)
- **convert.h** – header file with function prototypes
- **main.c** – the driver program that runs all the tests
- **README.md** – this file, explains the assignment and how I approached it
- **separated_tests/** – folder with all the test cases split up into three files:
  - `div_tests.txt` – all tests for `div_convert`
  - `sub_tests.txt` – all tests for `sub_convert`
  - `print_tests.txt` – all tests for `print_tables`

## Transparency Note

For this assignment I used outside resources to help me learn and finish the project.

- I used **W3Schools** to look up basic C concepts and syntax whenever I got stuck.
- I also used **AI assistance** to help me understand how to structure parts of my code, how to organize my test files, and to help me write this README in a way that explains my work clearly.

I tried my best to take what I learned from these resources and actually apply it myself instead of just copying. The goal for me was to get a firm grasp on C programming and build confidence step by step. This README also reflects my process, struggles, and how I worked through the assignment.

## How to build and run

To compile:

To build and run this program you need gcc installed. On Mac or Linux, open a terminal, cd into the A1 folder, then run `gcc -o a1 main.c convert.c` to compile and `./a1` to run (the `./` is required). On Windows, open Command Prompt or PowerShell, cd into the A1 folder, run `gcc -o a1.exe main.c convert.c` to compile, and then just type `a1.exe` to run (no `./` needed). After running, the program will go through division tests, subtraction tests, comparison tests, and print tables tests automatically.

```bash
gcc -o a1 main.c convert.c

```

Repo: https://github.com/M5-sich/cs3503-a1-michael-sich
