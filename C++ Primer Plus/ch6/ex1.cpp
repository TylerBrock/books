// ex1.cpp -- read and echo converter
#include <iostream>
#include <cctype>

int main()
{
    using namespace std;

    char ch;
    while (cin.get(ch) && ch != '@')
    {
        if (isdigit(ch))
            continue;

        if (isalpha(ch))
            if (islower(ch))
                ch = toupper(ch);
            else
                ch = tolower(ch);

        cout << ch;
    }

    cout << "Done!";
    return 0;
}
