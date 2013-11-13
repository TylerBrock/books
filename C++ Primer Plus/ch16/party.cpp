// party.cpp -- merge two sets of party invitees
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using std::set;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::inserter;
using std::set_union;

void print_name(const string& s);
set<string> combine_names(set<string> a, set<string> b);
set<string> collect_names();

int main()
{
    set<string> mat = collect_names();
    cout << "\ncollected the following names:\n";
    for_each(mat.begin(), mat.end(), print_name);
    cout << endl << endl;

    set<string> pat = collect_names();
    cout << "\ncollected the following names:\n";
    for_each(pat.begin(), pat.end(), print_name);
    cout << endl;

    vector<string> merged;
    cout << "\nmerged lists:\n";
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), inserter(merged, merged.begin()));
    for_each(merged.begin(), merged.end(), print_name);
    cout << endl;
}

void print_name(const string& s)
{
    cout << s << " ";
}

set<string> combine_names(set<string> a, set<string> b)
{
    return set<string>();
}

set<string> collect_names()
{
    cout << "Enter some names for the list:\n";
    string temp;
    set<string> names;

    while (cin >> temp && temp != "done")
        names.insert(temp);

    return names;
}
