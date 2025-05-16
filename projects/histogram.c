#include <stdio.h>
int main()
{
    int c;
    int count = 0;
    int arry[11] = {0};
    while ((c = getchar()) != EOF)
    {

        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (count != 0 && c < (sizeof(arry) / sizeof(arry[0])))
            {
                ++arry[count];
            }

            count = 0;
        }
        else
        {
            count++;
        }
    }
    for (int i = 1; i < (sizeof(arry) / sizeof(arry[0])); i++)
    {
        printf("Length %2d: ", i);
        for (int j = 0; j < arry[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}