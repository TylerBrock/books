// palindrome.cpp -- determine if a word is a palindrome
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

bool palindrome(string& s);

int main()
{
    string input;
    cout << "Enter a string to see if it's a palindrome (q to quit):\n";
    while (cin >> input && input != "q")
    {
        if (palindrome(input)) {
            cout << "The word " << input << " is a palindrome\n";
        } else {
            cout << "The word " << input << " is not a plaindrome\n";
        }
    }

    return 0;
}

bool palindrome(string& s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());

    if (temp == s)
        return true;
    else
        return false;
}

