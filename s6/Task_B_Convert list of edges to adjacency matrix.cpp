#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> temp(n);
	std::vector<std::vector<bool>> grath(n, std::vector<bool>(n));

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		grath[u - 1][v - 1] = 1;
	}
	
	for (const auto& line : grath) {
		for (int item : line) {
			std::cout << item << ' ';
		}
		std::cout << '\n';
	}
}