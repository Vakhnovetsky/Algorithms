#include <iostream>
#include <set>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::set<std::pair<int, int>> graph;

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		if (u < v) {
			graph.insert({u, v});
		}
		else {
			graph.insert({ v, u });
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (graph.count({ i, j }) == 0) {
				std::cout << "NO";
				return 0;
			}
		}
	}

	std::cout << "YES";
}