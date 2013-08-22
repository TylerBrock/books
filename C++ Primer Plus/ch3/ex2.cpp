// ex2.cpp -- calculate bmi
#include <iostream>

int main()
{
    using namespace std;
    const int inches_in_foot = 12;
    const float meters_per_inch = 0.0254;
    const float pounds_per_kg = 2.2;
    int feet;
    int inches;
    int weight;

    cout << "Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;
    cout << "Weight: ";
    cin >> weight;

    int height_in_inches = (feet * inches_in_foot) + inches;
    cout << "Height in inches: " << height_in_inches << endl;

    float height_in_meters = height_in_inches * meters_per_inch;
    cout << "Height in meters: " << height_in_meters << endl;

    float mass_in_kg = weight / pounds_per_kg;
    cout << "Mass in kilograms: " << mass_in_kg << endl;

    int bmi = mass_in_kg / (height_in_meters * height_in_meters);

    cout << "BMI: " << bmi << endl;

    return 0;
}
