#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	std::string line1, line2;
	std::unordered_map<char, char> dic1, dic2;

	std::getline(std::cin, line1);
	std::getline(std::cin, line2);

	if (line1.size() != line2.size()) {
		std::cout << "NO";
		return 0;
	}

	for (int i = 0; i < line1.size(); ++i) {
		if (dic1.find(line1[i]) == dic1.end()) {
			dic1[line1[i]] = line2[i];
		}

		if (dic2.find(line2[i]) == dic2.end()) {
			dic2[line2[i]] = line1[i];
		}

		if (dic1[line1[i]] != line2[i] || dic2[line2[i]] != line1[i]) {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
}