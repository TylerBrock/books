// ex1.cpp -- default args example
#include <iostream>

using namespace std;

void print(const char * str, int n = 0);

int main()
{
    const char * name = "Tyler Brock";

    print(name);
    print(name, 3);
    print(name);
    print(name, 123);

    return 0;
}

void print(const char * str, int n)
{
    static int count = 0;

    if(n)
        for (int i = 0; i < count; i++)
            cout << str << endl;
    else
        cout << str << endl;

    count++;
}
