// ex7.cpp -- pizza analysis
#include <iostream>

struct pizza_place {
    std::string name;
    float diameter;
    float weight;
};

int main()
{
    using namespace std;

    pizza_place place;

    cout << "Name: ";
    getline(cin, place.name);
    cout << "Diameter: ";
    cin >> place.diameter;
    cout << "Weight: ";
    cin >> place.weight;

    // print the pizza place info
    cout << "Name: " << place.name << endl;
    cout << "Diameter: " << place.diameter << endl;
    cout << "Weight: " << place.weight << endl;

    return 0;
}
