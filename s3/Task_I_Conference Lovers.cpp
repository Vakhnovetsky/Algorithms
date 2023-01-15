#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, k;

	std::cin >> n;
	const int id_num = 10000;

	std::vector<int> universities(id_num, 0);

	for (int i = 0; i < n; ++i) {
		int id;
		std::cin >> id;
		++universities[id];
	}

	std::cin >> k;

	std::vector<std::pair<int, int>> ids;

	for (int i = 0; i < id_num; ++i) {
		if (universities[i] > 0) {
			ids.push_back({ -1 * universities[i], i });
		}
	}

	std::sort(ids.begin(), ids.end());

	for (int i = 0; i < k; ++i) {
		std::cout << ids[i].second << ' ';
	}
}
