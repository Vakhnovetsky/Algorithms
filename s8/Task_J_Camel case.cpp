#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

struct Node {
	std::map<char, Node*> list;
	std::vector<int> terminal;
};

void AddWordToTree(Node* root, std::vector<std::string>& words, int id) {
	Node* current_node = root;
	current_node->terminal.push_back(id);

	for (char ch : words[id]) {
		if (ch >= 'A' && ch <= 'Z') {
			if (current_node->list.find(ch) == current_node->list.end()) {
				Node* new_node = new Node;
				current_node->list[ch] = new_node;
				current_node = new_node;
			}
			else {
				current_node = current_node->list[ch];
			}

			current_node->terminal.push_back(id);
		}
	}
}

void FindWords(std::string_view pattern, Node* root, std::vector<std::string>& words, std::vector<std::string>& result) {
	int current_symbol = 0;

	Node* next_node = root;

	while (current_symbol != pattern.size() && !next_node->list.empty()) {
		auto iter = next_node->list.find(pattern[current_symbol]);

		if (iter == next_node->list.end()) {
			break;
		}

		if (iter->first == pattern[current_symbol]) {
			++current_symbol;
			next_node = iter->second;
		}
	}

	if (current_symbol == pattern.size()) {
		for (int id : next_node->terminal) {
			result.push_back(words[id]);
		}
	}
}

int main() {
	int n, m;
	std::cin >> n; 
	Node* root = new Node;
	std::vector<std::string> words;

	for (int i = 0; i < n; ++i) {
		std::string word;
		std::cin >> word;
		words.push_back(word);
		AddWordToTree(root, words, i);
	}

	std::cin >> m;
	std::vector<std::string> patterns;
	
	std::string pattern;
	std::getline(std::cin, pattern);

	for (int i = 0; i < m; ++i) {
		std::getline(std::cin, pattern);
		patterns.push_back(pattern);
	}

	for (std::string& pattern: patterns) {
		std::vector<std::string> result;

		FindWords(pattern, root, words, result);

		std::sort(result.begin(), result.end());

		if (result.size() > 0) {
			for (std::string& word : result) {
				std::cout << word << '\n';
			}
		}
		else {
			std::cout << '\n';
		}
	}
}