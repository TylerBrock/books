#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;

    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from the stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
