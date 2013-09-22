// stone.cpp -- user-defined conversion
// compile with stonewt.cpp
#include <iostream>
#include "stonewt1.h"

void display(const Stonewt & st, int n);

int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8);	// 9 stone, 2.8 pounds
	double p_wt = poppins;		// implicit conversion
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int(poppins) << " pounds.\n";
	return 0;
}