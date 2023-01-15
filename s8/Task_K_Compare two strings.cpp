#include <iostream>
#include <string>

int main() {
	std::string a, b;
	std::cin >> a >> b;

	int i_a = 0;
	int i_b = 0;

	while (i_a != a.size() && i_b != b.size()) {
		while (i_a != a.size() && a[i_a] % 2 !=0) {
			++i_a;
		}

		while (i_b != b.size() && b[i_b] % 2 != 0) {
			++i_b;
		}

		if (i_a != a.size() && i_b != b.size()) {
			if (a[i_a] == b[i_b]) {
				++i_a;
				++i_b;
			}
			else if (a[i_a] < b[i_b]) {
				std::cout << -1;
				return 0;
			}
			else {
				std::cout << 1;
				return 0;
			}
		}
		else {
			if (i_a == a.size() && i_b != b.size()) {
				std::cout << -1;
				return 0;
			}
			else if (i_a != a.size() && i_b == b.size()) {
				std::cout << 1;
				return 0;
			}
		}
	}

	std::cout << 0;
}