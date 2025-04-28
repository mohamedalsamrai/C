#include <stdio.h>
#define INTI_VALUE 0
#define MAX_VALUE 300
#define STEP 20
int main()
{
    int fahr, celsius;
    fahr = INTI_VALUE;
    while (fahr <= MAX_VALUE)
    {
        celsius = (5 * (fahr - 32) / 9);
        printf("%3d %3d\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}