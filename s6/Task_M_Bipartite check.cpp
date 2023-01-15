#include <iostream>
#include <queue>
#include <set>
#include <vector>

enum class Color {
	white, gray, black
};

enum class Side {
	left, right, middle
};

std::string BFS(int s, std::vector<std::vector<int>>& graph, std::vector<Color>& color, std::vector<Side>& side) {
	std::queue<int> planned;
	planned.push(s);
	side[s] = Side::left;

	while (!planned.empty()) {
		if (color[planned.front()] == Color::white) {
			color[planned.front()] = Color::gray;

			for (int v : graph[planned.front()]) {
				if (color[v] == Color::white) {
					planned.push(v);
					if (side[planned.front()] == Side::left) {
						side[v] = Side::right;
					}
					else {
						side[v] = Side::left;
					}
				}
				else {
					if (side[planned.front()] == side[v]) {
						return "NO";
						
					}
				}
			}
		}
		else if (color[planned.front()] == Color::gray) {
			color[planned.front()] = Color::black;
			planned.pop();
		}
		else if (color[planned.front()] == Color::black) {
			planned.pop();
		}
	}

	return "YES";
}

int main() {
	int n, m, s;
	std::cin >> n >> m;
	std::vector<Color> color(n + 1, Color::white);
	std::vector<Side> side(n + 1, Side::middle);
	std::vector<std::vector<int>> graph(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		s = u;
	}

	if (m != 0) {
		for (int i = 1; i < color.size(); ++i) {
			if (color[i] == Color::white) {
				std::string res = BFS(i, graph, color, side);
				if (res == "NO") {
					std::cout << res;
					return 0;
				}
			}
		}
	}

	std::cout << "YES";
}