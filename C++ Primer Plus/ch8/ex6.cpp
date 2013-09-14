// ex6.cpp -- maxn
#include <iostream>
#include <cstring>

template <typename T>
T maxn(T numbers[], int n);

template <>
const char * maxn<const char *>(const char * strings[], int n);

int main()
{
    using namespace std;

    int integers[] = {9, 10, 23, 12};
    double doubs[] = {1, 21, 111.10, 102, 13, 22};
    const char * strings[] = {
        "Awesome",
        "Bogus bongos are like dingos",
        "Dudddddddee"
    };

    cout << "Integers: ";
    for (int i = 0; i < 4; i++)
        cout << integers[i] << " ";
    cout << endl;

    cout << "Max integer: " << maxn(integers, 4) << endl;

    cout << "Doubles: ";
    for (int i = 0; i < 6; i++)
        cout << doubs[i] << " ";
    cout << endl;

    cout << "Max double: " << maxn(doubs, 6) << endl;

    cout << "Strings: ";
    for (int i = 0; i < 3; i++)
        cout << strings[i] << " ";
    cout << endl;

    cout << "Longest string: " << maxn(strings, 3) << endl;

    return 0;
}

template <typename T>
T maxn(T numbers[], int n)
{
    T max = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

template <>
const char * maxn<const char *>(const char * strings[], int n)
{
    const char * longest = strings[0];

    for (int i = 1; i < n; i++)
    {
        if (strlen(strings[i]) > strlen(longest))
            longest = strings[i];
    }
    return longest;
}
