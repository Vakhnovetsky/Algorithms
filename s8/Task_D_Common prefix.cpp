#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;

	std::cin >> n;
	std::string f_str;

	std::cin >> f_str;

	int max = f_str.size();

	for (int i = 1; i < n; ++i) {
		std::string str;
		std::cin >> str;

		while (max > 0) {
			if (f_str.substr(0, max) == str.substr(0, max)) {
				break;
			}
			--max;
		}
	}

	std::cout << max;
}