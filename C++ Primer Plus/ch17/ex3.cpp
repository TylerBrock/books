// ex3.cpp -- copy files
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        cerr << "usage: " << argv[0] << " source destination\n";
        exit(EXIT_FAILURE);
    }

    ifstream in(argv[1]);
    ofstream out(argv[2]);

    if (in.is_open() && out.is_open())
    {
        char ch;

        while (in.get(ch) && ch != EOF)
        {
            out << ch;
        }
    } else
    {
        cerr << "could not open both files";
    }

    in.close();
    out.close();

    return 0;
}
