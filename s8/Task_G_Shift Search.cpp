#include <cmath>
#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::vector<int> x;
	std::vector<int> pattern;
	std::vector<int> positions;

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		x.push_back(temp);
	}

	std::cin >> m;

	for (int i = 0; i < m; ++i) {
		int temp;
		std::cin >> temp;
		pattern.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		int c = x[i] - pattern[0];

		for (int j = 0; j < m; ++j) {
			if (j + i == n || x[j + i] != pattern[j] + c) {
				break;
			}

			if (j == m - 1) {
				positions.push_back(i + 1);
			}
		}
	}

	for (int pos : positions) {
		std::cout << pos << ' ';
	}
}