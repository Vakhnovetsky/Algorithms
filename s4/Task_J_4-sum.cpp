#include <algorithm>
#include <iostream>
#include <tuple>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

struct hashFunction
{
	size_t operator()(const std::tuple<int, int, int, int>& x) const
	{
		return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x) ^ std::get<3>(x);
	}
};

int main()
{
	int num;
	int64_t A, target;
	std::unordered_set<std::tuple<int, int, int, int>, hashFunction> triples;
	std::unordered_map<int64_t, std::set<std::pair<int, int>>> history;

	std::vector<int> x;

	std::cin >> num >> A;
	for (int i = 0; i < num; ++i) {
		int temp;
		std::cin >> temp;
		x.push_back(temp);
	}

	std::sort(x.begin(), x.end());

	for (int i = 0; i < x.size(); ++i) {
		for (int j = i + 1; j < x.size(); ++j) {
			target = A - x[i] - x[j];

			if (history.find(target) != history.end()) {
				for (const auto t: history[target]) {
					if (t.first != j && t.first != i && t.second != j && t.second != i) {
						std::vector<int> triple{ x[t.first], x[t.second], x[i], x[j] };
						std::sort(triple.begin(), triple.end());
						triples.insert({ triple[0], triple[1], triple[2], triple[3] });
					}
				}
			}

			history[x[i] + x[j]].insert({ i, j });
		}
	}

	std::vector<std::tuple<int, int, int, int>> result;

	for (auto& triple : triples) {
		result.push_back(triple);
	}

	std::sort(result.begin(), result.end());

	std::cout << result.size() << '\n';

	for (auto& triple : result) {
		std::cout << std::get<0>(triple) << ' '
			<< std::get<1>(triple) << ' '
			<< std::get<2>(triple) << ' '
			<< std::get<3>(triple) << '\n';
	}
}