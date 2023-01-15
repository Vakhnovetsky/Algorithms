#include <algorithm>
#include <iostream>
#include <string>

int main() {
	int number;
	std::cin >> number;
	std::string res;

	if(number==0) {
    	std::cout << 0;
    	return 0;
	}

	while (number >= 1) {
		res += std::to_string(number % 2);
		number /= 2;
	}

	std::reverse(res.begin(), res.end());

	std::cout << res;
}