// ex2.cpp -- golf scores
#include <iostream>

using namespace std;

const int ArSize = 10;
void input_scores(int [], int);
void print_scores(const int [], int);
double average_scores(const int[], int);

int main()
{
    int scores[ArSize];

    input_scores(scores, ArSize);
    print_scores(scores, ArSize);
    double average = average_scores(scores, ArSize);

    cout << "The average is " << average << endl;

    return 0;
}

void input_scores(int scores[], int size)
{
    cout << "Enter " << ArSize << " score(s). ";
    cout << "Type a negative number to exit.\n";

    int score;

    for (int i = 0; i < ArSize; i++)
    {
        cout << "Score #" << i + 1 << ": ";

        cin >> score;
        scores[i] = score;

        if (score < 0)
            break;
    }
}

void print_scores(const int scores[], int size)
{
    for (int i = 0; i < ArSize && (scores[i] >= 0); i++)
        cout << scores[i] << ", ";
}

double average_scores(const int scores[], int size)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < ArSize && (scores[i] >= 0); i++)
    {
        sum += scores[i];
        count++;
    }

    return sum / count;
}
