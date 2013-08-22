// assgn_st.cpp -- assigning structures
#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;

    inflatable boquet =
    {
        "sunflowers",
        0.20,
        12.49
    };

    inflatable choice;
    cout << "boquet: " << boquet.name << " for $";
    cout << boquet.price << endl;

    choice = boquet;    //assign one structure to another
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;

    return 0;
}
