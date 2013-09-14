// sales.cpp
#include <iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        int num_sales = n < QUARTERS ? n : QUARTERS;
        double min, max, average, total = 0;

        min = max = ar[0];

        for (int i = 0; i < num_sales; i++)
        {
            s.sales[i] = ar[i];
            if (ar[i] < min)
                min = ar[i];
            else if (ar[i] > max)
                max = ar[i];
            total += ar[i];
        }

        for (int i = num_sales; i < QUARTERS; i++)
            s.sales[i] = 0;

        s.max = max;
        s.min = min;

        average = total / num_sales;
        s.average = average;
    }

    void setSales(Sales & s)
    {
        using namespace std;

        double qt,min,max,average,total = 0;

        cout << endl;
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "Enter sales for quarter #" << i + 1 << ": ";
            cin >> qt;
            s.sales[i] = qt;
            total += qt;
        }

        min = max = s.sales[0];
        for (int i = 0; i < QUARTERS; i++)
        {
            if (min > s.sales[i])
                min = s.sales[i];
            else if (max < s.sales[i])
                max = s.sales[i];
        }

        average = total / QUARTERS;
        s.average = average;
        s.max = max;
        s.min = min;
    }

    void showSales(const Sales & s)
    {
        using namespace std;

        cout << "--- Sales ---" << endl;
        for (int i = 0; i < 4; i++)
            cout << "Quarter " << i + 1 << ": " << s.sales[i] << endl;

        cout << "Average: " << s.average << endl;
        cout << "Maximum: " << s.max << endl;
        cout << "Minimum: " << s.min << endl;
        cout << endl;
    }
}
