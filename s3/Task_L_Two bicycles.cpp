#include <cmath>
#include <iostream>
#include <vector>

int FindDay(std::vector<int>& wallet, int s, int begin, int end) {
	int mid = (begin + end) / 2;
	if (wallet[mid] >= s && (mid == 0 || wallet[mid - 1] < s)) {
		return mid + 1;
	}
	else if (begin >= end) {
		return -1;
	}
	else if (wallet[mid] >= s) {
		return FindDay(wallet, s, begin, mid);
	}
	else {
		return FindDay(wallet, s, mid+1, end);
	}
}

int main() {
	int n, s;
	std::cin >> n;

	std::vector<int> wallet;

	for (int i = 0; i < n; ++i) {
		int money;
		std::cin >> money;
		wallet.push_back(money);
	}

	std::cin >> s;

	int day = FindDay(wallet, s, 0, n - 1);
	int day2 = FindDay(wallet, s * 2, 0, n - 1);

	std::cout << day << " " << day2;
}