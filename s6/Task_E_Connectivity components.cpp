#include <iostream>
#include <functional>
#include <set>
#include <stack>
#include <vector>

void DFS(int s, std::vector<std::set<int, std::greater<int>>>& graph, std::vector<int>& color, std::vector<std::set<int>>& result, int component_count) {
	std::stack<int> st;
	st.push(s);
	std::set<int> component;

	while (!st.empty()) {
		if (color[st.top()] == -1) {
			color[st.top()] = 0;
			for (int v : graph[st.top()]) {
				if (color[v] == -1) {
					st.push(v);
				}
			}
		}
		else if (color[st.top()] == 0) {
			color[st.top()] = component_count;
			component.insert(st.top());
			st.pop();
		}
		else if (color[st.top()] > 0) {
			st.pop();
		}
	}

	result.push_back(component);
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> color(n + 1, -1);
	std::vector<std::set <int, std::greater<int>>> graph(n + 1);
	int component_count = 0;

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	std::vector<std::set<int>> result;
	
	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			++component_count;
			DFS(i, graph, color, result, component_count);
		}
	}

	std::cout << component_count << '\n';
	for (const auto& component : result) {
		for (int v : component) {
			std::cout << v << ' ';
		}
		std::cout << '\n';
	}
}
