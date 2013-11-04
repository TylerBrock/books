// winec2.h -- headers for the wine class
#ifndef WINEC2_H_
#define WINEC2_H_
#include <string>
#include <iostream>
#include <valarray>
#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
    private:
        int years;

    public:
        // initialize label to l, number of years to y,
        // vintage years to yr[], bottles to bot[]
        Wine(const char * l, int y, const int yr[], const int bot[]);

        // initialize label to l, number of years to y,
        // create array objects of length y
        Wine(const char* l, int y);

        // Get input about this particular wine from the user
        void GetBottles();

        // Show information about a wine
        void Show() const;

        // Returns a reference to the wine name
        std::string & Label();

        // Total number of bottles in the second item of PairArray
        int sum() const;
};

#endif
