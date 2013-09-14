// ex2.cpp -- candybar
#include <iostream>

using namespace std;

struct CandyBar
{
    const char * brand;
    double weight;
    int calories;
};

void set_info(CandyBar & cb, const char * brand = "Millenium Munch",
    double weight = 2.85, int calories = 350);
void print_info(const CandyBar & cb);

int main()
{
    CandyBar cb;
    set_info(cb);
    print_info(cb);

    set_info(cb, "Tyler Bar");
    print_info(cb);

    set_info(cb, "Awesome Bar", 123.11, 1000);
    print_info(cb);

    return 0;
}

void set_info(CandyBar & cb, const char * brand, double weight, int calories)
{
    cb.brand = brand;
    cb.weight = weight;
    cb.calories = calories;
}

void print_info(const CandyBar & cb)
{
    cout << "--- Candy Bar ---" << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calories << endl;
}
