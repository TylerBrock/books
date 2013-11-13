// reduce.cpp -- sort and remove duplicates
#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

const int SIZE = 7;

int main()
{
    using std::cout;
    using std::endl;

    long nums[] = { 66, 11, 22, 33, 44, 44, 55 };
    cout << "The original array:\n";
    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";
    cout << endl;

    int new_size = reduce(nums, SIZE);

    for (int i = 0; i < new_size; i++)
        cout << nums[i] << " ";

    cout << endl;
}

int reduce(long ar[], int n)
{
    using std::sort;
    using std::unique;

    sort(ar, ar + n);
    int size = unique(ar, ar + n) - ar;

    return size;
}
