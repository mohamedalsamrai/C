#include <stdio.h>

int main()
{
    int digit_count[10] = {0}; // initialize all elements to 0
    int c, nWhite, nOther;
    nWhite = nOther = 0;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++digit_count[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            nWhite++;
        }
        else
        {
            nOther++;
        }
    }
    printf("Digits:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i, digit_count[i]);
    }
    printf("Whitespace characters: %d\n", nWhite);
    printf("Other characters: %d\n", nOther);
    return 0;
}