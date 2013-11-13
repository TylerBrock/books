// lotto.cpp -- lottery number generator
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::vector;

vector<int> Lotto(int spots, int numbers);

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;

    int spots, numbers;

    cout << "Enter the number of spots on the Lotto card:\n";
    cin >> spots;
    cout << "Enter the amount of numbers to choose:\n";
    cin >> numbers;

    vector<int> choices;

    if (spots < numbers) {
        cout << "You cant choose that many numbers from those spots!\n";
        exit(EXIT_FAILURE);
    } else
        choices = Lotto(spots, numbers);

    cout << "Here are your choices:\n";
    for (int i = 0; i < choices.size(); i++)
        cout << choices[i] << " ";

    cout << endl;

    return 0;
}

vector<int> Lotto(int spots, int numbers)
{
    vector<int> possibles;
    for (int i = 1; i <= spots; i++)
        possibles.push_back(i);

    random_shuffle(possibles.begin(), possibles.end());
    possibles.erase(possibles.begin() + numbers, possibles.end());

    return possibles;
}
