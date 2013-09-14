// funtemp.cpp -- using a function template
#include <iostream>

// fucntion template prototype
template <typename T> // or class T
void Swap(T &a, T &b);

int main()
{
    using namespace std;

    int i = 10;
    int j = 20;

    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler generated double swapper:\n";
    Swap(x,y);  // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y << ".\n";

    return 0;
}

// template function definition
template <typename T>   // or class T
void Swap(T &a, T &b)
{
    T temp;     // temp a variable of type T
    temp = a;
    a = b;
    b = temp;
}
