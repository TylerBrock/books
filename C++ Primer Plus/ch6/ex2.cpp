// ex2.cpp -- donation values sum and average
#include <iostream>
#include <array>

const int max_donations = 10;

int main()
{
    using namespace std;

    double sum = 0.0;
    array<double, max_donations> donations;
    int count;
    int larger;

    while (cin >> donations[count] && count <= max_donations)
    {
        sum += donations[count];
        count++;
    }


    cout << "Number of donations: " << count << endl;
    if (count != 0)
    {
        double average = sum / count;
        cout << "Average of donations: " << average << endl;

        for (int i = 0; i <= count; i++)
        {
            if (donations[i] > average)
            {
                cout << "Donation #" << i << " is greater than average" << endl;
                larger++;
            }
        }
    }

    return 0;
}
