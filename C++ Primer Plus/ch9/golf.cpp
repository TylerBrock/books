// golf.cpp -- implementations of functions in golf.h
#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
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

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using namespace std;

    cout << "--- Golf ---" << endl;
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
    cout << endl;
}
