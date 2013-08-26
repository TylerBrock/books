// ex1.cpp sum integers between two numbers
#include <iostream>

int main()
{
    using namespace std;

    int lower;
    int upper;

    cout << "Enter the lower bound: ";
    cin >> lower;
    cout << "Enter the upper bound: ";
    cin >> upper;

    int sum;

    for (; lower <= upper; lower++)
    {
        sum += lower;
    }

    cout << "The sum is " << sum << endl;

    return 0;
}
