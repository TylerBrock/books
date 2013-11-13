// reduce.cpp -- sort and remove duplicates
#include <iostream>
#include <algorithm>
#include <string>

template <class T>
int reduce(T ar[], int n);

const int SIZE = 7;

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    long nums[] = { 66, 11, 22, 33, 44, 44, 55 };
    string strings[] = { "tyler", "brock", "brock", "tyler", "test", "a", "a" };

    cout << "The original array of nums:\n";
    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";
    cout << endl;

    int new_size = reduce(nums, SIZE);

    cout << "The reduced array of nums:\n";
    for (int i = 0; i < new_size; i++)
        cout << nums[i] << " ";
    cout << endl;

    cout << "The original array of strings\n";
    for (int i = 0; i < SIZE; i++)
        cout << strings[i] << " ";
    cout << endl;

    new_size = reduce(strings, SIZE);

    cout << "The reduced array of strings:\n";
    for (int i = 0; i < new_size; i++)
        cout << strings[i] << " ";
    cout << endl;
}

template <class T>
int reduce(T ar[], int n)
{
    using std::sort;
    using std::unique;

    sort(ar, ar + n);
    int size = unique(ar, ar + n) - ar;

    return size;
}
