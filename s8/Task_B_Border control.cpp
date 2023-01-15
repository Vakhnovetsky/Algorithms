#include <cmath>
#include <iostream>
#include <string>
#include <string_view>

int main() {
	std::string a, b;
	std::cin >> a >> b;
	int counter = 0;

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) {
				++counter;
				if (counter > 1) {
					std::cout << "FAIL";
					return 0;
				}
			}
		}
	}
	else {
		if (std::abs(static_cast<int>(a.size() - b.size())) > 1) {
			std::cout << "FAIL";
			return 0;
		}

		std::string_view first, second;
		if (a.size() < b.size()) {
			first = a;
			second = b;
		}
		else {
			first = b;
			second = a;
		}

		int i = 0;
		int j = 0;

		while (i < first.size()) {
			if (first[i] == second[j]) {
				++i;
				++j;
			}
			else {
				if (i + 1 != first.size() && first[i + 1] == second[j + 1]) {
					++counter;
					++i;
					++j;
				}
				else if (i + 1 == first.size() || first[i] == second[j + 1]) {
					++counter;
					++j;
				}

				if (counter > 1) {
					std::cout << "FAIL";
					return 0;
				}
			}
		}

		if (i == j && counter > 0) {
			std::cout << "FAIL";
			return 0;
		}
	}

	std::cout << "OK";
}