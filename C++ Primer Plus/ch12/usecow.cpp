#include <iostream>
#include "cow.h"

using namespace std;

int main()
{
    Cow tyler;
    tyler.ShowCow();
    Cow steve = Cow("Fake Person", "Programming", 123);
    steve.ShowCow();
    tyler = steve;
    tyler.ShowCow();
}
