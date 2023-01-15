#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
#include <unordered_map>

void Relax(int u, int v, std::unordered_map<int, std::unordered_map<int, int>>& graph, std::vector<int>& distance, std::vector<int>& previous) {
	if (distance[v] > distance[u] + graph[u][v]) {
		distance[v] = distance[u] + graph[u][v];
		previous[v] = u;
	}
}

int get_min_dist_not_visited_vertex(std::vector<int>& visited, std::vector<int>& distance) {
	int current_minimum = std::numeric_limits<int>::max();
	int current_minimum_vertex = -1;

	for (int i = 1; i < visited.size(); ++i) {
		if (!visited[i] && distance[i] < current_minimum) {
			current_minimum = distance[i];
			current_minimum_vertex = i;
		}
	}
	return current_minimum_vertex;
}

void FindPath(int s, int n, std::unordered_map<int, std::unordered_map<int, int>>& graph) {
	std::vector<int> distance(n + 1, std::numeric_limits<int>::max());
	std::vector<int> previous(n + 1, -1);
	std::vector<int> visited(n + 1, false);

	distance[s] = 0;

	int u = get_min_dist_not_visited_vertex(visited, distance);
	while (u != -1) {
		visited[u] = true;
		if (graph.count(u) > 0) {
			const auto& neighbours = graph.at(u);
			for (const auto& ver : neighbours) {
				Relax(u, ver.first, graph, distance, previous);
			}
		}

		u = get_min_dist_not_visited_vertex(visited, distance);
	}

	for (int i = 1; i <= n; ++i) {
		if (distance[i] != std::numeric_limits<int>::max()) {
			std::cout << distance[i] << ' ';
		}
		else {
			std::cout << "-1 ";
		}

	}

	std::cout << '\n';
}

int main() {
	int n, m;
	std::cin >> n >> m;

	std::unordered_map <int, std::unordered_map<int, int>> graph;

	for (int i = 0; i < m; ++i) {
		int u, v, weight;
		std::cin >> u >> v >> weight;
		if (graph.count(u) > 0 && graph[u].count(v) > 0) {
			graph[u][v] = std::min(graph[u][v], weight);
			graph[v][u] = graph[u][v];
		}
		else {
			graph[u][v] = weight;
			graph[v][u] = weight;
		}
	}

	for (int i = 1; i <= n; ++i) {
		FindPath(i, n, graph);
	}
}