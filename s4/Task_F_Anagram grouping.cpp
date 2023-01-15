#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
	int n = 0;
	std::unordered_map<std::string, std::vector<int>> words;
	std::vector<std::string> words_name;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::string word;
		std::cin >> word;
		std::sort(word.begin(), word.end());
		if (words.find(word) != words.end()) {
			words[word].push_back(i);
		}
		else {
			words_name.push_back(word);
			words[word] = { i };
		}
	}

	for (auto& word: words_name) {
		for (int index: words[word]) {
			std::cout << index << ' ';
		}
		std::cout << '\n';
	}
}