// ex1.cpp
#include <iostream>
#include "golf.h"

int main()
{

    using namespace std;

    golf tb;
    setgolf(tb, "Tyler Brock", 18);

    golf mo;
    cout << setgolf(mo) << endl;

    showgolf(tb);
    showgolf(mo);

    handicap(tb,3);
    handicap(mo,6);

    showgolf(tb);
    showgolf(mo);

    return 0;
}
