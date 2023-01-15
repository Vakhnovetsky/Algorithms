#include <algorithm>
#include <iostream>
#include <queue>
#include <optional>
#include <set>
#include <vector>

void BFS(int s, std::vector<std::set<int>>& graph, std::vector<int>& color) {
	std::queue<int> planned;
	std::vector<std::optional<int>> distance(color.size());

	int max_distance = 0;
	planned.push(s);
	color[s] = 0;
	distance[s] = 0;

	while (!planned.empty()) {
		int u = planned.front();
		planned.pop();

		for (int v : graph[u]) {
			if (color[v] == -1) {
				if (distance[u].has_value()) {
					distance[v] = distance[u].value() + 1;
				}
				else {
					distance[v] = 1;
				}
				max_distance = std::max(distance[v].value(), max_distance);
				color[v] = 0;
				planned.push(v);
			}
		}
		color[u] = 1;
	}

	std::cout << max_distance;
}

int main() {
	int n, m, s;
	std::cin >> n >> m;
	std::vector<int> color(n + 1, -1);
	std::vector<std::set <int>> graph(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	std::cin >> s;
	BFS(s, graph, color);
}