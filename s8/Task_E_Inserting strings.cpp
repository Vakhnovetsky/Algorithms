#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility> 
#include <vector>

int main() {
	std::string line;
	int n;
	std::cin >> line >> n;

	std::vector<std::pair<int, std::string>> vec;

	for (int i = 0; i < n; ++i) {
		std::string str;
		int index;
		std::cin >> str >> index;
		vec.push_back({ index, str });
	}

	std::sort(vec.begin(), vec.end(), [](const auto& lhs, const auto& rhs) { return lhs.first > rhs.first; });

	int size = 0;
	std::map<int, std::string> answer;

	for (const auto& v : vec) {
		if (v.first < line.size()) {
			answer[size] = line.substr(v.first);
			line.erase(line.begin() + v.first, line.end());
			++size;
		}

		answer[size] = v.second;
		++size;
	}

	if (!line.empty()) {
		std::cout << line;
	}

	for (int i = size - 1; i >= 0; --i) {
		std::cout << answer[i];
	}
}