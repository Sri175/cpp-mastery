//Write a benchmark: insert 1M strings into vector with push_back vs emplace_back (measure time)
#include <chrono>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    constexpr int N = 1'000'000;

    {
        std::vector<std::string> v;

        auto start =
            std::chrono::high_resolution_clock::now();

        for(int i=0;i<N;i++)
        {
            v.push_back("hello");
        }

        auto end =
            std::chrono::high_resolution_clock::now();

        std::cout
            << "push_back: "
            << std::chrono::duration<double>(end-start).count()
            << " sec\n";
    }

    {
        std::vector<std::string> v;

        auto start =
            std::chrono::high_resolution_clock::now();

        for(int i=0;i<N;i++)
        {
            v.emplace_back("hello");
        }

        auto end =
            std::chrono::high_resolution_clock::now();

        std::cout
            << "emplace_back: "
            << std::chrono::duration<double>(end-start).count()
            << " sec\n";
    }
}