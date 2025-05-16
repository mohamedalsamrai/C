#include <stdio.h>
#define INTI_VALUE 0 // constant
#define MAX_VALUE 300
#define STEP 20
int main()
{
    int digit_count[10]; // declare without initialization
    int arr[10] = {0}; // initialize all elements to 0
    int arr[10] = {1, 2, 3}; // initialize first three elements to 1, 2, 3 and the rest to 0
    float fahr, celsius; // declare without initialization
    fahr = INTI_VALUE;
    for (fahr; fahr <= MAX_VALUE; fahr += STEP)
    {
        celsius = (5.0 * (fahr - 32.0) / 9.0);
        printf("%3.0f %6.2f\n", fahr, celsius);
    }
    return 0;
}