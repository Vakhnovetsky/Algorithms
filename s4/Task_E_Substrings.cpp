#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	size_t n = 0;
	std::string str;
	std::cin >> str;
	std::unordered_set<char> letters;
	int begin = 0;

	for (char ch : str) {
		if (letters.find(ch) != letters.end()) {
			n = std::max(letters.size(), n);
			while (str[begin] != ch) {
				letters.erase(str[begin]);
				++begin;
			}
			++begin;
		}
		else {
			letters.insert(ch);
		}

	}
	n = std::max(letters.size(), n);

	std::cout << n;
}