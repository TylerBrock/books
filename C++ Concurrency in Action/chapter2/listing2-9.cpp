#include <thread>
#include <iostream>
#include <numeric>
#include <vector>
#include <mutex>
#include <sstream>

std::mutex mtx;

void log(std::string msg) {
    mtx.lock();
    std::cout << msg;
    mtx.unlock();
}

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        std::stringstream ss;
        ss << "[thread] running inside of: " << std::this_thread::get_id() << std::endl;
        log(ss.str());
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);
    if (!length)
        return init;
    else
        std::cout << "distance: " << length << std::endl;

    unsigned long const min_per_thread=25;
    unsigned long const max_threads=(length + min_per_thread - 1) / min_per_thread;
    std::cout << "max_threads: " << max_threads << std::endl;

    unsigned long const hardware_threads=std::thread::hardware_concurrency();
    bool has_hw_threads = hardware_threads != 0;

    unsigned long const num_threads=std::min(has_hw_threads ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length/num_threads;
    std::cout << "num_threads: " << num_threads << std::endl;
    std::cout << "block_size: " << block_size << std::endl;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);
    Iterator block_start=first;

    // Each thread stores it's result in the results vector which has pre-allocated the space
    // Starts 1 less thread than needed because current thread counts as running thread
    for(unsigned long i=0; i<(num_threads-1); ++i)
    {
        Iterator block_end=block_start;
        std::advance(block_end, block_size);
        threads[i]=std::thread(
            accumulate_block<Iterator, T>(),
            block_start,
            block_end,
            std::ref(results[i])
        );
        block_start=block_end;
    }
    // Make sure the final block is accumulated
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads-1]);

    for(auto& entry: threads)
        entry.join();

    // Count up all the results in the results array
    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    std::cout << "hardware concurrency: " << std::thread::hardware_concurrency() << std::endl;

    std::vector<long> v;
    for (unsigned long long i=0; i<100000; ++i)
    {
        v.push_back(i);
    }

    long long init = 0;
    long long result = parallel_accumulate(v.cbegin(), v.cend(), init);
    std::cout << "result: " << result << std::endl;

    return 0;
}