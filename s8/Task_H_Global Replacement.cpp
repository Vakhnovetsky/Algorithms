#include <iostream>
#include <string>
#include <vector>

std::vector<int> find(std::string& text, std::string& pattern) {
	std::vector<int> result;
	std::string s(pattern + '#' + text);
	std::vector<int> pi(pattern.size());
	int pi_prev = 0;

	for (int i = 1; i < s.size(); ++i) {
		int k = pi_prev;

		while (k > 0 && s[k] != s[i]) {
			k = pi[k - 1];
		}

		if (s[k] == s[i]) {
			++k;
		}

		if (i < pattern.size()) {
			pi[i] = k;
		}

		pi_prev = k;

		if (k == pattern.size()) {
			result.push_back(i - 2 * pattern.size());
		}
	}
	return result;
}

int main() {
	std::string text, pattern, t;
	std::cin >> text >> pattern >> t;

	std::vector<int> res_find = find(text, pattern);

	for (auto iter = res_find.rbegin(); iter != res_find.rend(); ++iter) {
		text.replace(*iter, pattern.size(), t);
	}

	std::cout << text;
}