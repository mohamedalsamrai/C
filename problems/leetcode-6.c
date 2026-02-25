/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int zigzag_cols(int L, int rows)
{
    if (rows <= 1 || L <= 0)
        return L;

    int cycleLen = 2 * rows - 2;
    int full = L / cycleLen;
    int rem = L % cycleLen;

    int cols = full * (rows - 1);

    if (rem <= rows && rem > 0)
    {
        cols += 1;
    }
    else if (rem > rows)
    {
        cols += 1 + (rem - rows);
    }

    return cols;
}

char *convert(const char *s, int numRows)
{
    int L = strlen(s);
    if (numRows <= 1 || L <= 1)
    {

        char *out = (char *)malloc(L + 1);
        memcpy(out, s, L + 1);
        return out;
    }

    int cols = zigzag_cols(L, numRows);
    int (*a)[cols] = malloc(numRows * sizeof *a);

    memset(a, -1, numRows * sizeof *a);
    int row = 0, col = 0;
    int down = 1;

    for (int i = 0; i < L; i++)
    {
        a[row][col] = (unsigned char)s[i];

        if (down)
        {
            if (row == numRows - 1)
            {
                down = 0;
                row--;
                col++;
            }
            else
            {
                row++;
            }
        }
        else
        {
            if (row == 0)
            {
                down = 1;
                row++;
            }
            else
            {
                row--;
                col++;
            }
        }
    }

    char *r = (char *)malloc(L + 1);

    int k = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] != -1)
            {
                r[k++] = (char)a[i][j];
            }
        }
    }
    r[k] = '\0';

    free(a);
    return r;
}


int main(void)
{
    const char *s = "PAYPALISHIRING";
    int rows = 4;

    char *out = convert(s, rows);
    if (!out)
        return 1;

    printf("%s\n", out);
    free(out);

    return 0;
}