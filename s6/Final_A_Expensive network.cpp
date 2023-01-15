/*
Задача. A. Дорогая сеть
Описание. Подсчет веса максимального остовного дерева используя алгоритм Прима на очереди с приоритетом

ВРЕМЕННАЯ СЛОЖНОСТЬ
Cложность алгоритма O(E*log(V)), где E — количество ребер, V — количество вершин.
Хранение ребер, исходящих из уже собранного подмножества остова, осуществляется в очереди с приоритетом. 
На каждом шаге добавляем в очередь ребра, идущие из текущей вершины в вершины еще не добавленные в остов, и забираем максимальное по весу ребро.
Если ребро соединяет две вершины, уже добавленные в остов, то оно отбрасывается из рассмотрения. 
Поскольку добавление и удаление ребер из очереди осуществляется с логарифмической сложностью, то поиск очередного максимального по весу ребра
осуществляется также с логарифмической сложностью. 

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Используется дополнительная память под массив vertices вершин, для проверки добавленных вершин в остов О(V).
Также под очередь с приоритетом not_added под ребра, которые не добавлены в остов О(E).
Суммарное использование дополнительной памяти О(E).
*/

#include <iostream>
#include <queue>
#include <vector>

struct Edge {
	int u;
	int v;
	int w;

	Edge(int u1 = 0, int v1 = 0, int w1 = 0) {
		u = u1;
		v = v1;
		w = w1;
	}
};

bool operator<(const Edge& lhs, const Edge& rhs) {
	return lhs.w < rhs.w;
}

void FindMaxWeight(int u, std::vector<std::vector<int>>& graph, std::vector<bool>& vertices, std::priority_queue<Edge>& not_added) {
	for (int v = 1; v < graph[u].size(); ++v) {
		if (graph[u][v] > 0 && !vertices[v]) {
			not_added.push({ u, v, graph[u][v] });
		}
	}

	while (!not_added.empty() && vertices[not_added.top().v]) {
		not_added.pop();
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));
	std::vector<bool> vertices(n + 1);

	std::priority_queue<Edge> not_added;
	int sum = 0;
	int current_vertex;

	int u, v, w;
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v >> w;

		graph[u][v] = std::max(w, graph[u][v]);
		graph[v][u] = graph[u][v];
	}

	int added = 1;

	if(m > 0) {
		current_vertex = u;
		while (added < n) {
			vertices[current_vertex] = true;
			FindMaxWeight(current_vertex, graph, vertices, not_added);
			if (not_added.empty()) {
				break;
			}

			current_vertex = not_added.top().v;
			sum += not_added.top().w;
			not_added.pop();
			++added;
		}
	}

	if (added == n) {
		std::cout << sum;
	}
	else {
		std::cout << "Oops! I did it again";
	}
}