#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> array;

	for (int i = 0; i < n; ++i) {
		int item;
		std::cin >> item;
		array.push_back(item);
	}

	std::sort(array.begin(), array.end(), [](int l, int r) {return l > r; });

	for (int i = 0; i < array.size()-2; ++i) {
		if (array[i] < array[i + 1] + array[i + 2]) {
			std::cout << array[i] + array[i + 1] + array[i + 2];
			return 0;
		}
	}
}