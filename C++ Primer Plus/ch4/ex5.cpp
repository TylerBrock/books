// ex5.cpp -- candybar structure
#include <iostream>
#include <string>


struct CandyBar {
    std::string brand;
    float weight;
    int calories;
};

int main()
{
    using namespace std;

    CandyBar snack = {"Mocha Munch", 2.3, 350};

    cout << "Snack name: " << snack.brand << endl;
    cout << "Snake weight: " << snack.weight << endl;
    cout << "Snack Calories: " << snack.calories << endl;

    return 0;
}
