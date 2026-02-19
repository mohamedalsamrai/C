#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char *s)
{
    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int left = 0;
    int best = 0;

    for (int right = 0; s[right] != '\0'; right++)
    {
        unsigned char c = (unsigned char)s[right];

        if (last[c] >= left)
        {
            left = last[c] + 1;
        }

        last[c] = right;

        int cur = right - left + 1;
        if (cur > best)
            best = cur;
    }

    return best;
}

int main()
{
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("abczafiaoimd"));
    printf("%d\n", lengthOfLongestSubstring(""));
    printf("%d\n", lengthOfLongestSubstring(" "));
    return 0;
}
