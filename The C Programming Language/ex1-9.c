#include <stdio.h>

int main(void)
{
    int c;
    int prev;

    prev = EOF;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            if (prev != ' ')
                putchar(c);
        if (c != ' ')
            putchar(c);
        prev = c;
    }
    return 0;
}
