// golf.cpp -- implementations of functions in golf.h
#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf()
{
    setgolf(*this);
}

Golf::Golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int Golf::setgolf(Golf & g)
{
    using namespace std;

    cout << "Enter name: ";
    cin.getline(g.fullname, Len);

    if (cin.eof())
        return 0;

    cout << "Enter handicap: ";
    cin >> g.handicap;

    return 1;
}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf()
{
    using namespace std;

    cout << "--- Golf ---" << endl;
    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
    cout << endl;
}
