#include <iostream>
#include <string>

int main() {
	std::string s, t;
	std::cin >> s >> t;
	int i = 0;
	for (char ch : t) {
		if (ch == s[i]) {
			++i;
			if (i == s.size()) {
				std::cout << "True";
				return 0;
			}

		}
	}

	std::cout << "False";
}