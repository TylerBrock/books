// palindrome2.cpp -- determine if a word is a palindrome
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::string;

bool palindrome(string& s);

int main()
{
    string input;
    cout << "Enter a string to see if it's a palindrome (q to quit):\n";
    while (getline(cin, input) && input != "q")
    {
        if (palindrome(input)) {
            cout << "The string " << input << " is a palindrome\n";
        } else {
            cout << "The string " << input << " is not a plaindrome\n";
        }
    }

    return 0;
}

bool palindrome(string& s)
{
    string stripped;

    for (int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
            stripped += tolower(s[i]);
    }

    string reversed = stripped;
    reverse(reversed.begin(), reversed.end());

    if (reversed == stripped)
        return true;
    else
        return false;
}

