#include <iostream>
#include <string>

double square(double x)
{
    return x*x;
}

// strongly typed enumerator
enum class Color {red, blue, green, pink};

class complex {
    double im, re;
public:
    complex() : re(0), im(0) {}
    complex(double r, double i) : re(r), im(i) {}

    complex operator+=(complex z) { return {re += z.re, im += z.im}; }
};

int main()
{
    std::string s{"I'm learning C++"};
    std::string first_name, last_name;
    double age;
    std::string previous = "";
    std::string name;

    double d = -257.345;
    int i{d};
    char c = i;
    int ii2 = c;
    std::cout << "d == " << d << std::endl;
    std::cout << "i == " << i << std::endl;
    std::cout << "c == " << c << std::endl;
    std::cout << "ii2 == " << ii2 << std::endl;
    int a = 1000;
    char bb = a;
    a = bb;

    std::cout << a << std::endl;

    while (std::cin >> name) {
        if (name == previous)
            std::cout << "Repeated: " << name << std::endl;
        previous = name;
    }

    std::cin >> first_name >> last_name >> age;
 
    std::cout << first_name << " " << last_name <<
        ", age in months: " << age * 12 << std::endl;
    
    if (s == "Are you done?")
        std::cout << "He's done." << std::endl;
    else
        std::cout << "He's still working." << std::endl;

    s[4] = 'L';
    std::string sub = s.substr(4, 8);
    s.replace(13, 3, "everything");
    std::cout << sub << " " << s << std::endl;
    
    int n = 4.32;
    float n1 {3.42};

    auto b = true;
    auto f = 1.2;

    complex z1;
    complex z2(2.3, 7);
    complex z3{2.1, 4.3};
    
    z1 += z2; // z1 = z1 + z2

    static_assert(sizeof(int) >= 4, "integers are too small");

    Color color = Color::red;
    if (color == Color::red)
        std::cout << "red" << std::endl;

    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "The length of v is " << sizeof(v)/sizeof(int) << std::endl;

    // C-like for-statement
    // for (int i = 0; i < sizeof(v)/sizeof(int); i++)
    //     printf("%d\n", v[i]);
    
    // // range-for-statement
    // for (auto x: v)
    //     std::cout << x << std::endl;

    // for (auto x: {2.3, 43.1, 32.0002, 1.2384})
    //     std::cout << x << std::endl;

    // for (auto &x: v)
    //     x++;
    // std::cout << "---------------" << std::endl;
    // for (auto x: v)
    //     std::cout << x << std::endl;

    int *p; // pointer to int
    int &r = n; // reference to int
    double *p1 = nullptr; // null pointer
    
    std::cout << "Hello, World!" << std::endl;
    std::cout << "The square of " << 1.234 << " is " << square(1.234) << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "n1 = " << n1 << std::endl;
    return 0;
}
