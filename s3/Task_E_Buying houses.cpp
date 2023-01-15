#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> houses;

	for (int i = 0; i < n; ++i) {
		int house;
		std::cin >> house;
		houses.push_back(house);
	}

	std::sort(houses.begin(), houses.end());

	int num_houses = 0;
	for (int house: houses) {
		if (k >= house) {
			k -= house;
			++num_houses;
		}
		else {
			break;
		}
	}


	std::cout << num_houses;
}