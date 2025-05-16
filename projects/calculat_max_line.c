#include <stdio.h>

int getLine(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}

int main()
{
    int max = 0;
    int len;
    char lin[1000];
    char maxLine[1000];
    while ((len = getLine(lin, 1000)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(maxLine, lin);
        }
    }
    if (max > 0)
    {
        printf("%s", maxLine);
    }
    return 0;
}