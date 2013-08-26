// ex6.cpp -- monetary contributions management output
#include <iostream>
#include <string>

using namespace std;

struct contribution {
    string name;
    double amount;
};

int main()
{
    cout << "Enter the number of contributors: ";
    int n_contributors;
    (cin >> n_contributors).get();

    contribution * contributions = new contribution[n_contributors];

    for (int i = 0; i < n_contributors; i++)
    {
        cout << "Name: ";
        getline(cin, contributions[i].name);
        cout << "Amount: ";
        (cin >> contributions[i].amount).get();
    }

    cout << "-----Grand Patrons-----\n";
    bool grandpatrons = false;

    for (int i = 0; i < n_contributors; i++)
    {
        if (contributions[i].amount >= 10000)
        {
            cout << contributions[i].name << endl;
            grandpatrons = true;
        }
    }
    if (grandpatrons == false)
        cout << "none.\n";

    cout << endl;

    cout << "-----Patrons-----\n";
    bool patrons = false;
    for (int i = 0; i < n_contributors; i++)
    {
        if (contributions[i].amount < 10000)
        {
            cout << contributions[i].name << endl;
            patrons = true;
        }
    }
    if (patrons == false)
        cout << "none.\n";

    delete [] contributions;

    return 0;
}
