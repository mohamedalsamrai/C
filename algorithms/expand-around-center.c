#include <stdlib.h>
#include <string.h>

static int expand(const char *s, int n, int L, int R)
{
    while (L >= 0 && R < n && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}

char *longestPalindrome(char *s)
{
    int n = (int)strlen(s);
    if (n == 0)
    {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int bestLen = 1;
    int bestStart = 0;

    for (int i = 0; i < n; i++)
    {
        int len1 = expand(s, n, i, i);
        int len2 = expand(s, n, i, i + 1);
        int len = (len1 > len2) ? len1 : len2;

        if (len > bestLen)
        {
            bestLen = len;
            bestStart = i - (len - 1) / 2;
        }
    }

    char *ans = (char *)malloc(bestLen + 1);
    memcpy(ans, s + bestStart, bestLen);
    ans[bestLen] = '\0';
    return ans;
}