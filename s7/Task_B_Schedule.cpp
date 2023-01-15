#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<double, double>> schedule;
	std::vector<std::pair<double, double>> res;

	for (int i = 0; i < n; ++i) {
		double start, finish;
		std::cin >> start >> finish;
		schedule.push_back({ finish, start });
	}

	std::sort(schedule.begin(), schedule.end());

	res.push_back(schedule.front());
	for (int i = 1; i < schedule.size(); ++i) {
		if (schedule[i].second >= res.back().first) {
			res.push_back(schedule[i]);
		}
	}

	std::cout << res.size() << '\n';
	for (const auto& lesson: res) {
		std::cout << lesson.second << ' ' << lesson.first << '\n';
	}
}