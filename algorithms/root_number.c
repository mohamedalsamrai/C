#include <stdio.h>
#include <stdint.h>
/*
this function to calculate bit length for n 
n>>=1 mean n=n>>1 to the right 
when n = 0x0000 loop stop and return bit length 
*/
static unsigned bit_length_uint64(uint64_t n) {
    unsigned k = 0;
    while (n) { k++; n >>= 1; }
    return k;
}
double guess_init_point(double n) {
    if (n <= 0.0) return 0.0;
    double guess;
    if (n >= 1.0) {
        uint64_t ui = (uint64_t)n;             
        unsigned k = bit_length_uint64(ui);    
        unsigned m = (k - 1) / 2;              
            uint64_t base = 1ULL << (m + 1);
        guess = (double)base;
        return guess;
    } else {
        guess = 1.0;
        return guess;
    }
}
double sqrt(double n) {
    double guess = guess_init_point(n);
    double epsilon = 0.00001;
    while ((guess * guess - n) > epsilon || (guess * guess - n) < -epsilon) {
        guess = (guess + n / guess) * 0.5; 
    }
    return guess;
}

int main() {
    double number = 786;
    printf("الجذر التربيعي لـ %.2f هو ≈ %.5f\n", number, sqrt(number));
    return 0;
}
