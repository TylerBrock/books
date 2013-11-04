// winec.cpp -- implementation of the Wine class
#include "winec2.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : std::string(l),
    PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), years(y)
{
}

Wine::Wine(const char * l, int y) : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)), years(y)
{
}

void Wine::GetBottles()
{
    for(int i = 0; i < years; i++)
    {
        std::cout << "Please enter a vintage year:";
        std::cin >> first()[i];
        std::cout << "Please enter the number of bottles:";
        std::cin >> second()[i];
    }
}

void Wine::Show() const
{
    std::cout << "Wine: " << std::string(*this) << std::endl;
    for (int i = 0; i < years; i++)
        std::cout << "Year " << first()[i]
                  << ": " << second()[i] << std::endl;
}

std::string & Wine::Label()
{
    return (std::string &)(*this);
}

int Wine::sum() const
{
    return second().sum();
}
