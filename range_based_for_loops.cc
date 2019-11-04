#include <iostream>
#include <vector>

int main() {
    std::vector<int> alpha{0, 1, 2, 3, 4, 5, 6};
    for (auto n : alpha) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    for (int n : {0, 1, 2, 3, 4, 5}) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    
    int array[]{0, 1, 2, 3, 4, 5, 6};
//    int array[] = {0, 1, 2, 3, 4, 5, 6};
    for (auto n : array) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::string sentence{"This is a sentence."};
    //std::string sentence("This is a sentence.");
    //std::string sentence = "This is a sentence.";
    for (auto c : sentence) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}