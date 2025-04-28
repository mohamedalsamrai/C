#include <stdio.h>
#include <stdbool.h>
int main()
{
    bool go =true;
    long nc;
    nc = 0;
    while (go)
    {
        ++nc;
        printf("%1d\n", nc);
    }

    return 0;
}