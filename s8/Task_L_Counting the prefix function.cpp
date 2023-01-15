#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string s;
	std::cin >> s;

	std::vector<int> pi(s.size());

	for (int i = 1; i < s.size(); ++i) {
		int k = pi[i - 1];
		
		while (k > 0 && s[k] != s[i]) {
			k = pi[k - 1];
		}

		if (s[k] == s[i]) {
			++k;
		}

		pi[i] = k;
	}

	for (int p : pi) {
		std::cout << p << ' ';
	}
}