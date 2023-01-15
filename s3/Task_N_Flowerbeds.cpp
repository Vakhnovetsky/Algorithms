#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> input;
	std::vector<std::pair<int, int>> res;
	input.reserve(n);

	for (int i = 0; i < n; ++i) {
		int left, right;
		std::cin >> left >> right;
		input.push_back({ left, right });
	}

	std::sort(input.begin(), input.end());
	
	for (auto item : input) {
		if (res.empty() || res.back().second < item.first) {
			res.push_back({ item.first, item.second });
		}
		else {
			res.back().second = std::max(res.back().second, item.second);
		}
	}

	for (auto item : res) {
		std::cout << item.first << ' ' << item.second << std::endl;
	}
}