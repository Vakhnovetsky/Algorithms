#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int k;
    std::cin >> k;
    std::cin.get();

    std::vector<int> keys(9, 0);
    std::string line;

    for (int i = 0; i < 4; ++i) {
        std::getline(std::cin, line);
        for (char ch : line) {
            if (std::isdigit(ch)) {
                ++keys[ch - '1'];
            }
        }
    }

    std::cout << std::count_if(keys.begin(), keys.end(), [k](int key) {return key > 0 && key <= k * 2; });
}