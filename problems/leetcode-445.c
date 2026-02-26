#include <stdlib.h>
static int cmp_int_asc(const void *p1, const void *p2)
{
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp_int_asc);
    qsort(s, sSize, sizeof(int), cmp_int_asc);

    int i = 0;
    int j = 0;
    int content = 0;

    while (i < gSize && j < sSize)
    {
        if (s[j] >= g[i])
        {
            content++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return content;
}