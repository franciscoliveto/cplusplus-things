#include <iostream>

int main(int argc, char *argv[])
{
    // int n = 5;
    // int n(5);
    int n{5};
    // double d = 1.2345;
    // double d(1.2345);
    double d{1.2345};
    // std::string s = "Hello";
    // std::string s("Hello");
    std::string s1{"Hello"};
    std::string s2{"Francisco"};
    // char c = '@';
    // char c('@');
    char c{'@'};
    // bool boolean(true);
    // bool boolean{true};
    bool boolean = true;

    std::cout << "n == " << n << std::endl;
    std::cout << "n+1 == " << n + 1 << std::endl;
    std::cout << "three times n == " << 3 * n << std::endl;
    std::cout << "twice n == " << n + n << std::endl;
    std::cout << "n squared == " << n * n << std::endl;
    std::cout << "half of n == " << n / 2 << std::endl;
    std::cout << "n-1 == " << n - 1 << std::endl;
    std::cout << "n++ == " << n++ << std::endl;
    std::cout << "n-- == " << n-- << std::endl;
    std::cout << "++n == " << ++n << std::endl;
    std::cout << "--n == " << --n << std::endl;
    std::cout << "n module 3 == " << n % 3 << std::endl;

    std::cout << "s1+s2 == " << s1 + " " + s2 << std::endl; 
    return 0;
}
