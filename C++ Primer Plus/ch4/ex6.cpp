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

    CandyBar snacks[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Mongo Bar", 5.5, 600},
        {"Bad Candy", 1.0, 120}
    };

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
