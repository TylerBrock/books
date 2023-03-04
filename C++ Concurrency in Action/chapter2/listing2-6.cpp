#include <thread>
#include <iostream>

void do_something(int i) {
    std::cout << "do_something: " << i << std::endl;
}

struct func
{
    int& i;
    func(int& i_):i(i_){}
    void operator()()
    {
        for(unsigned j=0; j<1000000; ++j)
        {
            do_something(i);
        }
    }
};

class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if (!t.joinable())
            throw std::logic_error("No thread!");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread operator=(scoped_thread const&)=delete;
};

void f()
{
    int some_local_state;
    scoped_thread t{std::thread(func(some_local_state))};
    do_something(1);
}

int main() {
    f();
}