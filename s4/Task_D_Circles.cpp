#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::string> vec;

	for (int i = 0; i < n; ++i) {
		std::string str;
		std::getline(std::cin, str, '\n');

		if (!str.empty()) {
			auto iter = std::find(vec.begin(), vec.end(), str);
			if (iter == vec.end()) {
				vec.push_back(str);
			}
		}
		else {
			++n;
		}
	}

	for (auto& v : vec) {
		std::cout << v << '\n';
	}
}