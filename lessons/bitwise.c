#include <stdio.h>
#define BITS sizeof(char) * 8
unsigned char rightrot(unsigned char x, int n)
{

    return (x >> n) | (x << (BITS - n));
}
unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{
   unsigned char c=0xff;
    c=(c<<BITS-(p+n))|(c>>BITS-p);
    x=x&c;
    y=y<<p;
    x=x|y;
    return x;

}

int main()
{
  unsigned char x=0b11011011;
  unsigned char y=0b00000011;
     x=setbits(x,2,2,y);
    printf("%p",x);

    return 0;
}