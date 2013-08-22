// ex4.cpp -- humanize seconds
#include <iostream>

int main()
{
    using namespace std;

    const int seconds_in_minute = 60;
    const int minutes_in_hour = 60;
    const int hours_in_day = 24;

    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    
