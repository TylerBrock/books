#include <iostream>

int main()
{
    using namespace std;

    cout << "What is your first name? ";
    char first[80];
    cin.getline(first, 80);
    cout << "What is your last name? ";
    char last[80];
    cin >> last;
    cout << "What letter grade do you deserve? ";
    char grade;
    cin >> grade;
    int age;
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << last << ", " << first << endl;
    cout << "Grade: " << char(grade + 1) << endl;
    cout << "Age: " << age << endl;

    return 0;
}
