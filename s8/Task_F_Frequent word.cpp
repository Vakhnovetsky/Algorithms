#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
	int n;
	std::unordered_map<std::string, int> buf;
	std::string answer;

	std::string line;
	std::cin >> n >> line;
	++buf[line];
	answer = line;
	int max = 1;

	for (int i = 1; i < n; ++i) {
		std::string line;
		std::cin >> line;
		++buf[line];

		if (max < buf[line] || max == buf[line] && answer > line) {
			answer = line;
			max = buf[line];
		}
	}

	std::cout << answer;
}