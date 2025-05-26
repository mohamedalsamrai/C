#include <stdio.h>
#include <math.h>
long long toInt64(int array[], int size);
int main()
{
    int D2[2][8] = {{109, 111, 104, 97, 109, 109, 101, 100},{32,97, 104, 109, 101, 100,}};
    long long ahmed64 = toInt64(D2[1], (sizeof(D2[1]) / sizeof(D2[1][0])));
    long long mohammed64 = toInt64(D2[0], (sizeof(D2[0]) / sizeof(D2[0][0])));
    char *p=(char *) &mohammed64;
    printf("\n\n");
    printf("mohammed in int64: %lld \nmohamed address: %p\n", mohammed64, &mohammed64);
    printf("ahmed in int64: %lld \nahmed address: %p\n", ahmed64, &ahmed64);
    for (int i = 0; i < (sizeof(D2[1]) / sizeof(D2[1][0]))+ (sizeof(D2[0]) / sizeof(D2[0][0])); i++)
    {
        printf("%c", *(p + i));
    }
}

long long toInt64(int array[], int size)
{
    long long b;

    long long s = 0;

    for (int i = 0; i < size; i++)
    {
        b = (long long)pow(256, i);
        s += (long long)(b * array[i]);
    }
    return s;
}