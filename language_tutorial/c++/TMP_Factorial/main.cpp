#include <iostream>

using namespace std;

template<long long n>
struct Factorial{
    enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0>{
    enum { value = 1 };
};

int main(void)
{
    cout << Factorial<10>::value << endl;
    cout << Factorial<5>::value << endl;

    return 0;
}