#include <iostream>
#include <functional>
#include <set>
#include <stack>
#include <vector>

void Go(int s, std::vector<std::set<int, std::greater<int>>>& graph, std::vector<int>& color) {
	std::stack<int> st;
	st.push(s);
	
	while (!st.empty()) {
		if (color[st.top()] == 0) {
			color[st.top()] = 1;
			std::cout << st.top() << ' ';
			for (int v: graph[st.top()]) {
				st.push(v);
			}
		}
		else if (color[st.top()] == 1) {
			color[st.top()] = 2;
			st.pop();
		}
		else if (color[st.top()] == 2) {
			st.pop();
		}
	}
}

int main() {
	int n, m, s;
	std::cin >> n >> m;
	std::vector<int> color(n + 1);
	std::vector<std::set <int, std::greater<int>>> graph(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	std::cin >> s;

	Go(s, graph, color);
}