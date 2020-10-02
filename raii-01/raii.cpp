#include <iostream>

//mail : jpenuchot@lri.fr

struct T
{
    T()
    {
        std::cout << this << " : constructed" << '\n';
    }

    T(T const &t)
    {
        std::cout << this << " : constructed from " << &t << '\n';
    }

    ~T()
    {
        std::cout << this << " : destructed" << '\n';
    }

    T &operator=(T const &t)
    {
        std::cout << this << ": copied from " << &t << '\n';
        return *this;
    }
};

void f1(T const &t)
{
}

void f2(T t) {}

T f3() { return T(); }

T f4()
{
    T t;
    return t;
}

void f5(T &t) { t = T(); }

struct U
{
    T v1, v2;
    U(T const &t) : v2(t) { v1 = t; }
};

int main()
{
    T a;
    f1(a);
    f2(a);
    T b = a;
    T c = f3();
    T d = f4();
    f5(d);
    U e(a);
}