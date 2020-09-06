#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> v = {5, 7, 9, 4, 6, 8};

    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    v.push_back(3);
    v.push_back(2);
    v.push_back(9);

    // range-for-loop
    for (int x : v)
        std::cout << x << " ";
    std::cout << std::endl;

    std::vector<double> values;
    for (double n; std::cin >> n;)
        values.push_back(n);

    sort(values.begin(), values.end());
    
    for (auto x : values)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
