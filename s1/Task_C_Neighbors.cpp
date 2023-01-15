#include <algorithm>
#include <iostream>
#include <vector>

int main() {

	int16_t n, m;
	std::vector<std::vector<int16_t>> matrix;

	std::cin >> m >> n;

	for (int16_t i = 0; i < m; ++i) {
		matrix.push_back({});
		for (int16_t j = 0; j < n; ++j) {
			int16_t temp;
			std::cin >> temp;
			matrix[i].push_back(temp);
		}
	}


	int16_t y, x;

	std::cin >> y >> x;

	std::vector<int16_t> res;

	if (x != n - 1) {
		res.push_back(matrix[y][x + 1]);
	}

	if (x != 0) {
		res.push_back(matrix[y][x - 1]);
	}

	if (y != 0) {
		res.push_back(matrix[y - 1][x]);
	}

	if(y != m - 1) {
		res.push_back(matrix[y + 1][x]);
	}

	std::sort(res.begin(), res.end());

	for (int16_t r : res) {
		std::cout << r << " ";
	}
}