#include <stdio.h>
#include "lesson.h"

#define EPSILON 0.000001

int test_get_average() {
    float result = get_average(3, 4, 5);
    float expected = 4.0;
    if (result - expected > EPSILON || expected - result > EPSILON) {
        printf("Test failed: get_average(3, 4, 5) = %f, expected %f\n", result, expected);
        return 0;
    }
    return 1;
}

int test_non_integer() {
    float result = get_average(3, 3, 5);
    float expected = 11.0 / 3.0;
    if (result - expected > EPSILON || expected - result > EPSILON) {
        printf("Test failed: get_average(3, 3, 5) = %f, expected %f\n", result, expected);
        return 0;
    }
    return 1;
}

int test_average_of_same() {
    float result = get_average(10, 10, 10);
    float expected = 10.0;
    if (result - expected > EPSILON || expected - result > EPSILON) {
        printf("Test failed: get_average(10, 10, 10) = %f, expected %f\n", result, expected);
        return 0;
    }
    return 1;
}

int test_average_of_big_numbers() {
    float result = get_average(1050, 2050, 2075);
    float expected = 1725.0;
    if (result - expected > EPSILON || expected - result > EPSILON) {
        printf("Test failed: get_average(1050, 2050, 2075) = %f, expected %f\n", result, expected);
        return 0;
    }
    return 1;
}

int main() {
    int tests_passed = 0;
    int total_tests = 4;

    printf("Running tests...\n");
    
    tests_passed += test_get_average();
    tests_passed += test_non_integer();
    tests_passed += test_average_of_same();
    tests_passed += test_average_of_big_numbers();

    printf("\nTest results: %d/%d tests passed\n", tests_passed, total_tests);
    return tests_passed == total_tests ? 0 : 1;
}
