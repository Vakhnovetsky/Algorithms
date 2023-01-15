#include <algorithm>
#include <iostream>
#include <string>

int main() {

	std::string str_s, str_t;

	std::getline(std::cin, str_s);
	std::getline(std::cin, str_t);

	std::sort(str_s.begin(), str_s.end());
	std::sort(str_t.begin(), str_t.end());

	for (int i = 0; i < str_s.size(); ++i) {
		if (str_s[i] != str_t[i]) {
			std::cout << str_t[i];
			return 0;
		}
	}

	std::cout << str_t.back();
}