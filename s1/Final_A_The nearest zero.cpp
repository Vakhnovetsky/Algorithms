#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int num;
    std::cin >> num;
    std::vector<int> street;
    std::vector<int> res;
    street.reserve(num);
    res.reserve(num);
    int zero_s = -2 * num;
    int zero_f = -2 * num;

    for (int i = 0; i < num; ++i) {
        int house;
        std::cin >> house;
        street.push_back(house);
    }

    for (int i = 0; i < num; ++i) {
        if (street[i] == 0) {
            zero_s = i;
        }
        res.push_back(std::abs(zero_s - i));
    }

    for (int i = num - 1; i >= 0; --i) {
        if (street[i] == 0) {
            zero_f = i;
        }

        res[i] = std::min(res[i], std::abs(zero_f - i));
    }

    for (int i = 0; i < num; ++i) {
        std::cout << res[i] << " ";
    }
}