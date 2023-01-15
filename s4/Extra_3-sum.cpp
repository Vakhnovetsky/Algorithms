#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

struct hashFunction
{
	size_t operator()(const std::tuple<int, int, int>& x) const
	{
		return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x);
	}
};

int main()
{
	int num, A;
	int target;
	std::unordered_set<std::tuple<int, int, int>, hashFunction> triples;
	std::unordered_set<int> history;
	
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
				triples.insert({ target, x[i], x[j] });
			}
		}

		history.insert(x[i]);
	}

	std::cout << triples.size() << '\n';
	for (auto& triple : triples) {
		std::cout << std::get<0>(triple) << ' ' << std::get<1>(triple) << ' ' << std::get<2>(triple) << '\n';
	}
}