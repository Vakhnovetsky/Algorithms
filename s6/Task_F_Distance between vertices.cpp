#include <iostream>
#include <queue>
#include <set>
#include <vector>

void BFS(int s, std::vector<std::set<int>>& graph, std::vector<int>& color, std::vector<int>& distance) {
	std::queue<int> planned;
	planned.push(s);
	color[s] = 0;
	distance[s] = 0;

	while (!planned.empty()) {
		int u = planned.front();
		planned.pop();

		for (int v : graph[u]) {
			if (color[v] == -1) {
				distance[v] = distance[u] + 1;
				color[v] = 0;
				planned.push(v);
			}
		}
		color[u] = 1;
	}
}

int main() {
	int n, m, s, f;
	std::cin >> n >> m;
	std::vector<int> color(n + 1, -1);
	std::vector<std::set <int>> graph(n + 1);
	std::vector<int> distance(n + 1, -1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	std::cin >> s >> f;
	BFS(s, graph, color, distance);
	std::cout << distance[f];
}