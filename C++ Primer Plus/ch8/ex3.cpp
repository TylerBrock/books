// ex3.cpp -- reference to string
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void upcase(string & str);

int main()
{
    string input;
    cout << "Enter a string (q to quit): ";
    getline(cin, input);

    while (input != "q")
    {
        upcase(input);
        cout << input << endl;
        cout << "Next string (q to quit): ";
        getline(cin, input);
    }

    return 0;
}

void upcase(string & str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
}
