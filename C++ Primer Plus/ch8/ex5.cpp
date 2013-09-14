// ex5.cpp -- template function
#include <iostream>

template <typename T>
T max5(T numbers[]);

int main()
{
    using namespace std;

    int integers[] = {9, 10, 23, 12, 2};
    double doubs[] = {1, 21, 111.10, 102, 3};

    cout << "Integers: ";
    for (int i = 0; i < 5; i++)
        cout << integers[i] << " ";
    cout << endl;

    cout << "Max integer: " << max5(integers) << endl;

    cout << "Doubles: ";
    for (int i = 0; i < 5; i++)
        cout << doubs[i] << " ";
    cout << endl;

    cout << "Max double: " << max5(doubs) << endl;

    return 0;
}

template <typename T>
T max5(T numbers[])
{
    T max = numbers[0];
    for (int i = 1; i < 5; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }

    return max;
}
