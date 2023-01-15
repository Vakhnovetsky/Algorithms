#include <iostream>
#include <string>

int main() {
	std::string word;
	std::string curr_word;

	int n;
	std::cin >> n;
	std::cin.get();

	for (int i = 0; i < n; ++i) {
		char c = std::cin.get();

		if (c == ' ') {
			if (curr_word.size() > word.size()) {
				word = curr_word;
			}
			curr_word.clear();
		}
		else {
			curr_word += c;
		}

	}

	if (curr_word.size() > 0 && curr_word.size() > word.size()) {
		word = curr_word;
	}

	std::cout << word << "\n" << word.size();
}