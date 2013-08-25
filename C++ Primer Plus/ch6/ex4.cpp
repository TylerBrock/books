// ex4.cpp -- Benevolent Order of Programmers
#include <iostream>

void showmenu();
void display_names();
void display_titles();
void display_bop();
void display_preference();

const int strsize = 25;

using namespace std;

struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

bop programmers[] = {
    {"Tyler J. Brock", "Software Engineer", "brock", 2},
    {"Michael O'Brien", "Software Engineer", "mpob", 0},
    {"Steve Francia", "Software Architect", "spf13", 2}
};

int main()
{

    showmenu();

    char choice;
    cin >> choice;

    while (choice != 'q'){
        switch(choice)
        {
            case 'a':   display_names();
                        break;
            case 'b':   display_titles();
                        break;
            case 'c':   display_bop();
                        break;
            case 'd':   display_preference();
                        break;
            default:    cout << "Bad choice hombre!\n";
        }
        showmenu();
        cin >> choice;
    }
    cout << "See ya!\n";
    return 0;
}

void showmenu()
{
    cout << "Benevolent Order of Programmers Report:\n"
         << "a. display by name     b. display by title\n"
         << "c. display by bopname  d. display by preference\n"
         << "q. quit\n";
}

void display_names()
{
    for (int i = 0; i < 3; i++)
        cout << programmers[i].fullname << endl;
}

void display_titles()
{
    for (int i = 0; i < 3; i++)
        cout << programmers[i].title << endl;
}

void display_bop()
{
    for (int i = 0; i < 3; i++)
        cout << programmers[i].bopname << endl;
}

void display_preference()
{
    for (int i = 0; i < 3; i++)
    {
        int preference = programmers[i].preference;
        switch (preference)
        {
            case 0:     cout << programmers[i].fullname << endl;
                        break;
            case 1:     cout << programmers[i].title << endl;
                        break;
            case 2:     cout << programmers[i].bopname << endl;
        }
    }
}
