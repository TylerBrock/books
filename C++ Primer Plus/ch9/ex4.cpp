#include <iostream>
#include "sales.h"

int main()
{
    double ar[3] = {100, 200, 300};
    SALES::Sales s1, s2;

    SALES::setSales(s1, ar, 3);
    SALES::showSales(s1);

    SALES::setSales(s2);
    SALES::showSales(s2);

    return 0;
}
