#include <stdio.h>

int main()
{
    int sneklang_default_max_threads = 8;
    char sneklang_default_perms = 'r';
    float sneklang_default_pi = 3.141592;
    char *sneklang_title = "Sneklang";
    printf("Default max threads: %d\nCustom perms: %c\nConstant pi value: %f\nSneklang title: %s\n",
           sneklang_default_max_threads,
           sneklang_default_perms,
           sneklang_default_pi,
           sneklang_title); // %d for int, %c for char, %f for float, %s for string


    float fahr, celsius;
    fahr = 0;
    for (fahr; fahr <= 300; fahr += 20)
    {
        celsius = (5.0 * (fahr - 32.0) / 9.0);
        printf("%3.0f %6.2f\n", fahr, celsius); // 3 digits for fahr, 6 digits for celsius .2 digits after the decimal point
    }
    return 0;
}
