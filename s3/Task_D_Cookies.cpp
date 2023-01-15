#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, m;

	std::cin >> n;

	std::vector<int> greeds;
	std::vector<int> cookies;

	for (int i = 0; i < n; ++i) {
		int greed;
		std::cin >> greed;
		greeds.push_back(greed);
	}

	std::cin >> m;

	for (int i = 0; i < m; ++i) {
		int cookie;
		std::cin >> cookie;
		cookies.push_back(cookie);
	}

	int res = 0;

	std::sort(greeds.begin(), greeds.end());
	std::sort(cookies.begin(), cookies.end());

	auto iter = cookies.begin();
	for (int greed : greeds) {
		while (iter != cookies.end() && greed > *iter) {
			++iter;
		}
		if (iter == cookies.end()) {
			break;
		}
		if (greed <= *iter) {
        	++iter;
			++res;
		}
	}

	std::cout << res;
}