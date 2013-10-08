#include <iostream>
#include <cstring>
#include "classic2.h"

Classic::Classic(const char * pw, const char * s1, const char * s2,
        int n, double x) : Cd(s1, s2, n, x)
{
    primary_work = new char[strlen(pw) + 1];
    strcpy(primary_work, pw);
}

Classic::Classic(const Classic & c) : Cd(c)
{
    primary_work = new char[strlen(c.primary_work) + 1];
    strcpy(primary_work, c.primary_work);
}

Classic::Classic() : Cd()
{
    primary_work = nullptr;
}

Classic::~Classic()
{
    delete [] primary_work;
}

void Classic::Report() const
{
    using std::cout;
    using std::endl;
    cout << "Primary Work: " << primary_work << endl;
    Cd::Report();
}

Classic & Classic::operator=(Classic const & c)
{
    if (this == &c)
        return *this;
    Cd::operator=(c);
    delete [] primary_work;
    primary_work = new char[strlen(c.primary_work) + 1];
    strcpy(primary_work, c.primary_work);
    return *this;
}
