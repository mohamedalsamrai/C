#include <stdio.h>
#define INTI_VALUE 0
#define MAX_VALUE 300
#define STEP 20
int main()
{
    float fahr, celsius;
    fahr = INTI_VALUE;
    while (fahr <= MAX_VALUE)
    {
        celsius = (5.0 * (fahr - 32.0) / 9.0);
        printf("%3.0f %6.2f\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}