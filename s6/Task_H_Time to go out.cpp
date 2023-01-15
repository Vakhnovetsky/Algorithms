#include <iostream>
#include <functional>
#include <set>
#include <stack>
#include <vector>

void DFS(int s, std::vector<std::set<int, std::greater<int>>>& graph, std::vector<int>& color, std::vector<int>& time_in, std::vector<int>& time_out) {
	int time = 0;
	std::stack<int> st;
	st.push(s);

	while (!st.empty()) {
		if (color[st.top()] == 0) {
			color[st.top()] = 1;
			time_in[st.top()] = time;
			for (int v : graph[st.top()]) {
				if (color[v] == 0) {
					st.push(v);
				}
			}
			++time;
		}
		else if (color[st.top()] == 1) {
			time_out[st.top()] = time;
			color[st.top()] = 2;
			st.pop();
			++time;
		}
		else if (color[st.top()] == 2) {
			st.pop();
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> color(n + 1);
	std::vector<int> time_in(n + 1, -1);
	std::vector<int> time_out(n + 1, -1);
	std::vector<std::set <int, std::greater<int>>> graph(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].insert(v);
	}

	DFS(1, graph, color, time_in, time_out);

	for (int i = 1; i <= n; ++i) {
		std::cout << time_in[i] << ' ' << time_out[i] << '\n';
	}
}