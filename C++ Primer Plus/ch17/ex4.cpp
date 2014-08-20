// ex4.cpp -- concat lines
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "usage: " << argv[0] << "input output\n";
        exit(EXIT_FAILURE);
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    return 0;
}
