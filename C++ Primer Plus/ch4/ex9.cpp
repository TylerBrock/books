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

    CandyBar * snacks = new CandyBar[3];

    snacks[0].brand = "Mocha Munch";
    snacks[0].weight = 2.3;
    snacks[0].calories = 350;

    snacks[1].brand = "Mongo Bar";
    snacks[1].weight = 5.5;
    snacks[1].calories = 600;

    snacks[2].brand = "Bad Candy";
    snacks[2].weight = 1.0;
    snacks[2].calories = 120;

    cout << "Snack name: " << snacks[0].brand << endl;
    cout << "Snake weight: " << snacks[0].weight << endl;
    cout << "Snack Calories: " << snacks[0].calories << endl;

    cout << "Snack name: " << snacks[1].brand << endl;
    cout << "Snake weight: " << snacks[1].weight << endl;
    cout << "Snack Calories: " << snacks[1].calories << endl;

    cout << "Snack name: " << snacks[2].brand << endl;
    cout << "Snake weight: " << snacks[2].weight << endl;
    cout << "Snack Calories: " << snacks[2].calories << endl;

    return 0;
}
