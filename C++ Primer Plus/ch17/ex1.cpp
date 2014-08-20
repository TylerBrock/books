// ex1.cpp -- count characters up to the first $
#include <iostream>

int main()
{
    using namespace std;

    int count;

    while (cin.get())
    {
        count++;
        if  (cin.peek() == '$')
            break;
    }

    cout << count << endl;
    return 0;
}
