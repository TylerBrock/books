// ex5.cpp -- factorial
#include <iostream>

int factorial(int);

int main()
{
    using namespace std;

    int number;
    cout << "Enter a number to get the factorial: ";

    while ((cin >> number).get() && number >= 0)
    {
        cout << "Factorial: " << factorial(number) << endl;
        cout << "Enter another number: ";
    }

    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
