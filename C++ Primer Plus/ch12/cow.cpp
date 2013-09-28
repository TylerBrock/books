#include <iostream>
#include <cstdlib>
#include "cow.h"

using namespace std;

Cow::Cow() {
    name[0] = '\0';
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strncpy(name, c.name, 20);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow(){
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)
        return *this;
    strncpy(name, c.name, 20);
    delete [] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    cout << "--- COW ---\n";
    cout << "Name: " << name << endl;
    if (hobby)
        cout << "Hobby: " << hobby << endl;
    cout << "Weight: " << weight << endl;
}
