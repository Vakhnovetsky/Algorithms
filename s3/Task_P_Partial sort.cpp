#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int res = 0;
	int max = 0;
	int curr_num = 0;

	for (int i = 0; i < n; ++i) {
		int temp_number;
		std::cin >> temp_number;
		max = std::max(max, temp_number);
		++curr_num;
		if (max + 1 == curr_num) {
			++res;
		}
	}
	std::cout << res;
}