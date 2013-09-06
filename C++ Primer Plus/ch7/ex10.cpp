// ex10.cpp -- calculate
#include <iostream>

double calculate(double x, double y, double (*pf)(double, double));
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

using namespace std;

int main()
{
    double x, y;
    double (*pf[4])(double, double) = {add, subtract, multiply, divide};

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        if (x < 0 || y < 0)
            break;

        for (int i = 0; i < 4; i++)
            cout << calculate(x, y, pf[i]) << endl;
    }
}

double calculate(double x, double y, double(*pf)(double, double))
{
    return pf(x, y);
}

double add (double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    return x / y;
}
