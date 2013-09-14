// ex4.cpp -- skeleton
#include <iostream>
#include <cstring>      // for strlen(), strcpy()

using namespace std;

struct stringy {
    char * str;     // points to a string
    int ct;         // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy & target, const char source[]);
void show(const stringy & str, int n = 1);
void show(const char * str, int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);    // first argument is a reference
            // allocates space to hold copy of testing,
            // sets str member of beany to point to the
            // new block, copies testing to new block,
            // and sets ct member of beany

    show(beany);        // prints member string once
    show(beany, 2);     // prints memebr string twice

    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);      // prints testing sring once
    show(testing, 3);   // prints testing string thrice

    show("Done!");

    delete [] beany.str;
    return 0;
}

void set(stringy & target, const char source[])
{
    int length = strlen(source);
    target.str = new char[length + 1];
    strcpy(copy, source);
    target.ct = length;
}

void show(const stringy & item, int n)
{
    for (int i = 0; i < n; i++)
        cout << item.str << endl;
}

void show(const char * str, int n)
{
    for (int i = 0; i < n; i++)
        cout << str << endl;
}
