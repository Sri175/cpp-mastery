#include <iostream>

template<int N>
constexpr int fib()
{
    if constexpr (N == 0)
        return 0;
    else if constexpr (N == 1)
        return 1;
    else
        return fib<N - 1>() + fib<N - 2>();
}

static_assert(fib<0>() == 0);
static_assert(fib<1>() == 1);
static_assert(fib<5>() == 5);
static_assert(fib<10>() == 55);

int main()
{
    std::cout << fib<10>() << '\n';
}