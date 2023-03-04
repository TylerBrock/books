#include <future>
#include <iostream>

int find_the_answer() { return 42; }

void do_other_stuff() {
    //lol
}

int main()
{
    std::future<int> the_answer = std::async(find_the_answer);
    do_other_stuff();
    std::cout << "the answer is " << the_answer.get() << std::endl;
}