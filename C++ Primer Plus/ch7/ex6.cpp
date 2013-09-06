// ex6.cpp -- fill, show, reverse array
#include <iostream>

using namespace std;

const int ArSize = 10;

int Fill_array(double [], int);
void Show_array(double [], int);
void Reverse_array(double [], int);

int main()
{
    double doubles[ArSize];

    // fill and print
    int size = Fill_array(doubles, ArSize);
    cout << "Size: " << size;
    Show_array(doubles, size);

    // now reversed
    Reverse_array(doubles, size);
    Show_array(doubles, size);

    // reverse all but the first and last
    Reverse_array(doubles + 1, size - 2);
    Show_array(doubles, size);

    return 0;
}

int Fill_array(double doubs[], int size)
{
    int count = 0;
    double mint;

    for (int i = 0; i < size; i++)
    {
        if (cin >> mint)
        {
            doubs[i] = mint;
            count++;
        } else
            break;
    }
    return count;
}

void Show_array(double doubs[], int size)
{
    for (int i = 0; i < size; i++)
        cout << doubs[i] << " ";
    cout << endl;
}

void Reverse_array(double doubs[], int size)
{
    double temp;
    for (int start = 0, end = size - 1; start < end; start++, end--)
    {
        temp = doubs[start];
        doubs[start] = doubs[end];
        doubs[end] = temp;
    }
}
