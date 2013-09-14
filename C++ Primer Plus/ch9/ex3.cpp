// ex3.cpp
#include <iostream>
#include <new>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;

    char * buffer = new char[sizeof(chaff) * 2];

    chaff * chaffs = new (buffer) chaff[2];

    strcpy(chaffs[0].dross, "Baus");
    chaffs[0].slag = 123;

    strcpy(chaffs[1].dross, "Baum");
    chaffs[1].slag = 456;

    for (int i = 0; i < 2; i++)
    {
        cout << "--- Chaff ---" << endl;
        cout << "Dross: " << chaffs[i].dross << endl;
        cout << "Slag: " << chaffs[i].slag << endl;
        cout << endl;
    }

    delete [] buffer;

    return 0;
}
