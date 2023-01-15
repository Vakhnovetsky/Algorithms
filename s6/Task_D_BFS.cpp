#include <iostream>
#include <queue>
#include <set>
#include <vector>

void BFS(int s, std::vector<std::set<int>>& graph, std::vector<int>& color) {
	std::queue<int> planned;
	planned.push(s);

	while (!planned.empty()) {
		if (color[planned.front()] == -1) {
			color[planned.front()] = 0;

			for (int v : graph[planned.front()]) {
				if (color[v] == -1) {
					planned.push(v);
				}
			}
		}
		else if (color[planned.front()] == 0) {
			color[planned.front()] = 1;
			std::cout << planned.front() << ' ';
			planned.pop();
		}
		else if (color[planned.front()] > 0) {
			planned.pop();
		}
	}
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
