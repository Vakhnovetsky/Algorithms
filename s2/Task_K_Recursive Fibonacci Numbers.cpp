#include <iostream>

int64_t Sum(int64_t n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		int64_t old = 1;
		int64_t res = 1;
		for (int i = 2; i <= n; ++i) {
			int64_t temp = res;
			res = res + old;
			old = temp;
		}
		return res;
	}
}

int main() {
	int64_t n;
	std::cin >> n;

	std::cout << Sum(n);
}