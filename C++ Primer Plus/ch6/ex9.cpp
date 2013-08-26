// ex9.cpp -- monetary contributions management w/ files
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct contribution {
    string name;
    double amount;
};

int main()
{
    ifstream inputFile;
    inputFile.open("contributions.txt");

    int n_contributors;
    (inputFile >> n_contributors).get();

    contribution * contributions = new contribution[n_contributors];

    for (int i = 0; i < n_contributors; i++)
    {
        getline(inputFile, contributions[i].name);
        (inputFile >> contributions[i].amount).get();
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
    inputFile.close();

    return 0;
}
