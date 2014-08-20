// ex2.cpp -- copies keyboard input to a file
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    using namespace std;

    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " filename\n";
        exit(EXIT_FAILURE);
    }

    ofstream ofile(argv[1]);

    char ch;

    while (cin.get(ch) && ch != EOF)
        ofile << ch;

    ofile.close();

    return 0;
}
