#include <iostream>
using namespace std;

bool accept()
{
    cout << "Do you want to proceed (y or n)?\n";

    char answer = 0;
    cin >> answer;

    if (answer == 'y') return true;
    return false;
}

int main()
{
    accept();
}

