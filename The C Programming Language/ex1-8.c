#include <stdio.h>

int main(void)
{
    int blanks, tabs, newlines;
    int c;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ') ++blanks;
        if (c == '\t') ++tabs;
        if (c == '\n') ++newlines;
    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, newlines);
}
