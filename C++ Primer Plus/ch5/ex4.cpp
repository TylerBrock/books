// ex4.cpp -- compound vs. simple interest
#include <iostream>

int main()
{
    using namespace std;

    double daphne = 100;
    double cleo = 100;
    int years = 0;

    do
    {
        daphne += 10;
        cleo *= 1.05;
        years += 1;
    } while (cleo <= daphne);

    cout << "It took " << years
         << " years for Cleo's balance to exceed Daphne's" << endl;

    cout << "Cleo: " << cleo << " Dapnhe: " << daphne << endl;

    return 0;
}
