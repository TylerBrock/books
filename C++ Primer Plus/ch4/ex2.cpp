#include <iostream>

int main()
{
    using namespace std;

    string first;
    string last;

    cout << "What is your first name? ";
    cin >> first;
    cout << "What is your last name? ";
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
