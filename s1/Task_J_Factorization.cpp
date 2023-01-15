#include <iostream>

int main() {
    int num;
    std::cin >> num;
    
    int del = 2;

    while (del * del <= num)
    {
        if (num % del != 0) {
            ++del;
        }
        else {
            num /= del;
            std::cout << del << " ";
        }
    }

    if (num > 1) {
        std::cout << num;
    }
}