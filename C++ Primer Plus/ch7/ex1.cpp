// ex1.cpp -- calculate harmonic mean
#include <iostream>

double harmonic_mean(double, double);

int main(){
    using namespace std;

    double x, y;

    cout << "Enter two numbers: ";

    while (cin >> x && cin >> y){
        if (x == 0 || y == 0)
            break;
        cout << harmonic_mean(x,y) << endl << endl;
        cout << "Enter two numbers: ";
    }

    return 0;
}

double harmonic_mean(double x, double y)
{
    return (2.0 * x * y) / (x + y);
}

