#include <iostream>
#include <unordered_map>

int main() {
	int n;
	std::cin >> n;

	std::unordered_map<int, std::pair<int, int>> dic;
	int len = 0, sum = 0;
	dic[sum] = { 0, 0 };

	for (int i = 1; i <= n; ++i) {
		int temp;
		std::cin >> temp;
		if (temp == 0) {
			--sum;
		}
		else if (temp == 1) {
			++sum;
		}

		if (dic.find(sum) == dic.end()) {
			dic[sum] = {i, i};
		}
		else {
			int first = dic[sum].first;
			dic[sum] = { first, i };
			if (len < i - first) {
				len = i - first;
			}
		}
	}

	std::cout << len;
}