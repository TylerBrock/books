#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(const char * pw, const char * s1, const char * s2,
        int n, double x) : Cd(s1, s2, n, x)
{
    strncpy(primary_work, pw, 49);
    primary_work[49] = '\0';
}

Classic::Classic()
{
    primary_work[0] = '\0';
}

void Classic::Report() const
{
    using std::cout;
    using std::endl;
    cout << "Primary Work: " << primary_work << endl;
    Cd::Report();
}
