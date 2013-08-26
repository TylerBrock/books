// ex7.cpp -- car structures
#include <iostream>
#include <string>

using namespace std;

struct car {
    string make;
    int year;
};

int main()
{
    cout << "How many cars? ";
    int num_cars;
    (cin >> num_cars).get();

    car * cars = new car[num_cars];

    for (int i = 0; i < num_cars; i++)
    {
        cout << "Car #" << i + 1 << endl;
        cout << "Please enter the make: ";
        getline(cin, cars[i].make);
        cout << "Please enter the year made: ";
        (cin >> cars[i].year).get();
    }

    cout << "Here is your collection:\n";

    for (int i = 0; i < num_cars; i++)
        cout << cars[i].year << " " << cars[i].make << endl;

    delete [] cars;

    return 0;
}
