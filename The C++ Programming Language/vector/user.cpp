#include "vector.h"
#include <cmath>
using namespace std;

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); i++)
        sum += sqrt(v[i]);
    return sum;
}
