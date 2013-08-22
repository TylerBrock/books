// ex3.cpp -- latitude converter
#include <iostream>

int main()
{
    using namespace std;

    int degrees;
    int minutes;
    int seconds;

    const float minutes_to_degree = 60;
    const float seconds_to_degree = minutes_to_degree * 60;

    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    float decimal = degrees + (minutes / minutes_to_degree)
        + (seconds / seconds_to_degree);
    cout << degrees << " degrees, " << minutes << " minutes ";
    cout << seconds << " seconds = " << decimal << " degrees";
    cout << endl;
    return 0;
}
