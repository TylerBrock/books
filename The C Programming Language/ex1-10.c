#include <stdio.h>

int main(void)
{
    int c;
    int prev;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
            c = EOF;
        }
        if (c == '\b')
        {
            printf("\\b");
            c = EOF;
        }
        if (c == '\\')
        {
            printf("\\\\");
            c = EOF;
        }
        if (c != EOF)
            putchar(c);
    }
    return 0;
}
