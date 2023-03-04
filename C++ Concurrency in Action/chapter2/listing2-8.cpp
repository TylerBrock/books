#include <vector>
#include <thread>
#include <iostream>

void do_something(int i) {
    std::cout << "do_something: " << i << std::endl;
}

void f() {
    std::vector<std::thread> threads;
    for (unsigned i=0; i<20; ++i)
    {
        threads.emplace_back(do_something, i);
    }
    for (auto& entry: threads)
        entry.join();
}

int main() {
    f();
}