#include <iostream>
#include <string>

int main() {
	int num;

	std::cin >> num;

	std::cin.get();

	char ch = std::cin.get();
	std::string x;
	while (ch != '\n') {
		if (ch != ' ') {
			x += ch;
		}
		ch = std::cin.get();
	}

	int k;
	std::cin >> k;

	std::string res = std::to_string(std::stoi(x) + k);

	for (auto c : res) {
		std::cout << c << " ";
	}
}