// winec.cpp -- implementation of the Wine class
#include <iostream>
#include "winec.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : name(l), years(y)
{
    ArrayInt vintage_years(yr, y);
    ArrayInt vintage_bottles(bot, y);
    p = std::make_pair(vintage_years, vintage_bottles);
}

Wine::Wine(const char * l, int y) : name(l), years(y)
{
    ArrayInt vintage_years(y);
    ArrayInt vintage_bottles(y);
    p = std::make_pair(vintage_years, vintage_bottles);
}

void Wine::GetBottles()
{
    for(int i = 0; i < years; i++)
    {
        std::cout << "Please enter a vintage year:";
        std::cin >> p.first[i];
        std::cout << "Please enter the number of bottles:";
        std::cin >> p.second[i];
    }
}

void Wine::Show() const
{
    std::cout << "Wine: " << name << std::endl;
    for (int i = 0; i < years; i++)
        std::cout << "Year " << p.first[i] << ": " << p.second[i] << std::endl;
}

std::string & Wine::Label()
{
    return name;
}

int Wine::sum() const
{
    return p.second.sum();
}
