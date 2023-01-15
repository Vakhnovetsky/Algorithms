#include <iostream>
#include <set>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::set<int>> graph(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u-1].insert(v);
	}

	for (const auto v : graph) {
		std::cout << v.size() << ' ';
		for (int vv : v) {
			std::cout << vv << ' ';
		}
		std::cout << '\n';
	}
}