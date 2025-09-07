#include <stdio.h>
#include <stdint.h>
#include<math.h>
/*
this function to calculate bit length for n
n>>=1 mean n=n>>1 to the right
when n = 0x0000 loop stop and return bit length
*/
static unsigned bit_length_uint64(uint64_t n)
{
    unsigned k = 0;
    while (n)
    {
        k++;
        n >>= 1;
    }
    return k;
}
double guess_init_point(double n)
{
    if (n <= 0.0)
        return 0.0;
    double guess;
    if (n >= 1.0)
    {
        uint64_t ui = (uint64_t)n;
        unsigned k = bit_length_uint64(ui);
        unsigned m = (k - 1) / 2;
        uint64_t base = 1ULL << (m + 1);
        guess = (double)base;
        return guess;
    }
    else
    {
        guess = 1.0;
        return guess;
    }
}
double sqrtx(double n)
{
    double guess = guess_init_point(n);
    double epsilon = 1e-5;
    while ((guess * guess - n) > epsilon)
    {
        guess = (guess + n / guess) * 0.5;
    }
    return guess;
}

int main()
{
    double number = 400000000007;
     printf("The root of %.2f = %.10f \n",number ,sqrtx(number));
     printf("The root of %.2f = %.10f",number ,sqrt(number));
    return 0;
}
