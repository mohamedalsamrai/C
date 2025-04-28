#include <stdio.h>
#include <stdbool.h>
int main()
{

    int c;
    bool lastWasSpace = false;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (!lastWasSpace)
            {
                putchar(c);
                lastWasSpace = true;
            }
        }
        else
        {
            putchar(c);
            lastWasSpace = false;
        }
    }
}