#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	int n, M;
	std::cin >> M >> n;
	std::vector<std::pair<long long, long long>> gold;
	long long value = 0;

	for (int i = 0; i < n; ++i) {
		int m, c;
		std::cin >> c >> m;
		gold.push_back({ c, m });
	}

	std::sort(gold.begin(), gold.end(), std::greater<std::pair<long long, long long>>());

	for (const auto heap: gold) {
		if (M >= heap.second) {
			M -= heap.second;
			value += (heap.first * heap.second);
		}
		else {
			value += (heap.first * M);
			break;
		}
	}

	std::cout << value;
}