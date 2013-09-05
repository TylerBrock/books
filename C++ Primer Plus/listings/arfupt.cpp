// arfupt.cpp -- an array of function pointers
#include <iostream>

// various notations, same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    // pointer to a function
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;   // C++11 automatic type deduction

    // pre-C++11 can use the following code instead
    // const double *(*p2)(const double *, int) = f2;

    cout << "Using pointers to functions:\n";
    cout << "Address\t\t Value\n";
    cout << (*p1)(av,3) << ":\t " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << ":\t " << *p2(av,3) << endl;

    // pa an array of pointers
    // auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1,f2,f3};

    // but it does work for initialized to a single value
    // pb a pointer to first element of pa
    auto pb = pa;

    // pre-C++11 can use the following code instead
    //const double *(**pb)(const double *, int) = pa;

    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << "Address\t\t Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;
}

const double * f1(const double * ar, int n)
{
    return ar;
}

const double * f2(const double ar[], int n)
{
    return ar+1;
}

const double * f3(const double ar[], int n)
{
    return ar+2;
}

