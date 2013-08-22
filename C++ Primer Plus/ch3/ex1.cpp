// ex1.cpp -- height converter
#include <iostream>

int main()
{
    using namespace std;

    const int inches_per_foot = 12;
    int height_inches;

    cout << "Enter your height in inches: ____" << "\b\b\b\b";
    cin >> height_inches;
    cout << "That is " << height_inches / inches_per_foot << " feet";
    cout << " and " << height_inches % inches_per_foot << " inches!";
    cout << endl;
    return 0;
}
