#include <iostream>
#include <string>
#include <utility>

// ------------------------------------
// Two overloads
// ------------------------------------

void foo(const std::string& s)
{
    std::cout << "LVALUE overload called: " << s << '\n';
}

void foo(std::string&& s)
{
    std::cout << "RVALUE overload called: " << s << '\n';
}

// ------------------------------------
// Bad wrapper
// loses original category
// ------------------------------------

template<typename T>
void wrapper_bad(T&& arg)
{
    std::cout << "wrapper_bad -> ";
    foo(arg); // arg has a name => lvalue
}

// ------------------------------------
// Force move
// always becomes rvalue
// ------------------------------------

template<typename T>
void wrapper_move(T&& arg)
{
    std::cout << "wrapper_move -> ";
    foo(std::move(arg));
}

// ------------------------------------
// Perfect forwarding
// preserves original category
// ------------------------------------

template<typename T>
void wrapper_forward(T&& arg)
{
    std::cout << "wrapper_forward -> ";
    foo(std::forward<T>(arg));
}

int main()
{
    std::string name{"Sri"};

    std::cout << "\n===== Direct Calls =====\n";

    foo(name);                     // lvalue
    foo(std::string("Temp"));      // rvalue
    foo(std::move(name));          // rvalue

    std::cout << "\n===== wrapper_bad =====\n";

    std::string a{"Alice"};

    wrapper_bad(a);
    wrapper_bad(std::string("Bob"));

    std::cout << "\n===== wrapper_move =====\n";

    std::string b{"Charlie"};

    wrapper_move(b);
    wrapper_move(std::string("David"));

    std::cout << "\n===== wrapper_forward =====\n";

    std::string c{"Emma"};

    wrapper_forward(c);
    wrapper_forward(std::string("Frank"));
}