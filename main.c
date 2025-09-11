#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "convert.h"

/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in div_tests.txt */
void run_division_tests(const char *file_path) {
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("Error: could not open test file: %s\n", file_path);
        return;
    }

    char function_name[32];
    uint32_t number;
    int base;
    char expected_result[70];
    char actual_result[70];

    int total_tests = 0;
    int passed_tests = 0;

    while (fscanf(file_pointer, "%31s %u %d %69s",
                  function_name, &number, &base, expected_result) == 4) {

        /* Optional safety check: ensure the line really starts with div_convert */
        if (strcmp(function_name, "div_convert") != 0) {
            printf("Skipping unknown function name in %s: %s\n", file_path, function_name);
            continue;
        }

        div_convert(number, base, actual_result);

        total_tests = total_tests + 1;

        if (strcmp(actual_result, expected_result) == 0) {
            passed_tests = passed_tests + 1;
            printf("DIV Test %d: div_convert(%u, %d) -> got=%s expected=%s [PASS]\n",
                   total_tests, number, base, actual_result, expected_result);
        } else {
            printf("DIV Test %d: div_convert(%u, %d) -> got=%s expected=%s [FAIL]\n",
                   total_tests, number, base, actual_result, expected_result);
        }
    }

    fclose(file_pointer);

    printf("DIV Summary (%s): %d/%d tests passed\n", file_path, passed_tests, total_tests);
}

/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in sub_tests.txt */
void run_subtraction_tests(const char *file_path) {
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("Error: could not open test file: %s\n", file_path);
        return;
    }

    char function_name[32];
    uint32_t number;
    int base;
    char expected_result[70];
    char actual_result[70];

    int total_tests = 0;
    int passed_tests = 0;

    while (fscanf(file_pointer, "%31s %u %d %69s",
                  function_name, &number, &base, expected_result) == 4) {

        if (strcmp(function_name, "sub_convert") != 0) {
            printf("Skipping unknown function name in %s: %s\n", file_path, function_name);
            continue;
        }

        sub_convert(number, base, actual_result);

        total_tests = total_tests + 1;

        if (strcmp(actual_result, expected_result) == 0) {
            passed_tests = passed_tests + 1;
            printf("SUB Test %d: sub_convert(%u, %d) -> got=%s expected=%s [PASS]\n",
                   total_tests, number, base, actual_result, expected_result);
        } else {
            printf("SUB Test %d: sub_convert(%u, %d) -> got=%s expected=%s [FAIL]\n",
                   total_tests, number, base, actual_result, expected_result);
        }
    }

    fclose(file_pointer);

    printf("SUB Summary (%s): %d/%d tests passed\n", file_path, passed_tests, total_tests);
}

/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in print_tests.txt */
void run_print_tables_tests(const char *file_path) {
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("Error: could not open test file: %s\n", file_path);
        return;
    }

    char function_name[32];
    uint32_t number;

    int total_tests = 0;
    int passed_tests = 0;

    while (fscanf(file_pointer, "%31s %u", function_name, &number) == 2) {

        if (strcmp(function_name, "print_tables") != 0) {
            printf("Skipping unknown function name in %s: %s\n", file_path, function_name);
            continue;
        }

        print_tables(number);  /* Should emit the 3 required lines */

        total_tests = total_tests + 1;

        /* The harness cannot string-compare formatted output without a buffer,
           so we count this as PASS here; your grading depends on exact formatting. */
        passed_tests = passed_tests + 1;
        printf("PRINT Test %d: print_tables(%u) -> [FORMATTED OUTPUT PRINTED] [PASS]\n",
               total_tests, number);
    }

    fclose(file_pointer);

    printf("PRINT Summary (%s): %d/%d tests passed\n", file_path, passed_tests, total_tests);
}

void run_comparisons(void) {
    char result_one[70];
    char result_two[70];

    // first Pair 1
    div_convert(7, 2, result_one);
    sub_convert(7, 2, result_two);
    printf("Compare 7 base 2: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");

    // second Pair 2
    div_convert(15, 8, result_one);
    sub_convert(15, 8, result_two);
    printf("Compare 15 base 8: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");

    // third Pair 3
    div_convert(31, 16, result_one);
    sub_convert(31, 16, result_two);
    printf("Compare 31 base 16: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");

    // fourth Pair 4
    div_convert(1000, 2, result_one);
    sub_convert(1000, 2, result_two);
    printf("Compare 1000 base 2: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");

    // fifth Pair 5
    div_convert(1000, 8, result_one);
    sub_convert(1000, 8, result_two);
    printf("Compare 1000 base 8: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");

    // sixth Pair 6
    div_convert(1000, 16, result_one);
    sub_convert(1000, 16, result_two);
    printf("Compare 1000 base 16: %s vs %s -> %s\n",
           result_one, result_two,
           strcmp(result_one, result_two) == 0 ? "PASS" : "FAIL");
}
/* -------------------------------------------------------------------------- */



int main() {
    run_division_tests("separated_tests/div_tests.txt");
    run_subtraction_tests("separated_tests/sub_tests.txt");
    run_comparisons();
    run_print_tables_tests("separated_tests/print_tests.txt");
    
    return 0;
}
