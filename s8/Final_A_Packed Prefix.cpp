/*
Задача: A. Packed Prefix
Описание. 
Даны строки в запакованном виде.
Требуется распаковать строки и найти наибольший общий префикс этих строк.

ВРЕМЕННАЯ СЛОЖНОСТЬ
О(n * L)
n - количество строк
L - длина наибольшей строки

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
О(L)
L - длина наибольшей строки
*/

#include <cctype>
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <vector>

std::string ParseLine(std::string line) {
	std::string result;
	std::stack<std::string> digits;
	std::deque<std::string> letters;

	bool is_digit = false, is_letter = false;

	for (char ch : line) {
		if (std::islower(ch)) {
			if (is_letter) {
				std::string l = letters.back();
				letters.pop_back();
				l.push_back(ch);
				letters.push_back(l);
			}
			else {
				is_digit = false;
				is_letter = true;
				letters.push_back({ ch });
			}
		}
		else if (std::isdigit(ch)) {
			if (is_digit) {
				std::string d = digits.top();
				digits.pop();
				d.push_back(ch);
				digits.push(d);
			}
			else {
				is_digit = true;
				is_letter = false;
				digits.push({ ch });
			}
		}
		else if (ch == ']') {
			std::string l = letters.back();
			int number = std::stoi(digits.top());
			digits.pop();
			for (int j = 1; j < number; ++j) {
				l += letters.back();
			}
			letters.pop_back();
			letters.pop_back();
			if (letters.empty() || letters.back() == "[") {
				letters.push_back(l);
			}
			else {
				letters[letters.size() - 1] += l;
			}
			is_digit = false;
			is_letter = false;
		}
		else if (ch == '[') {
			letters.push_back("[");
			is_digit = false;
			is_letter = false;
		}
	}

	while (!letters.empty()) {
		result += letters.front();
		letters.pop_front();
	}

	return result;
}

void FindMaxPrefix(int n) {
	std::string line;
	std::cin >> line;

	std::string word = ParseLine(line);
	int count = word.size();

	for (int i = 1; i < n; ++i) {
		std::cin >> line;
		std::string next_word = ParseLine(line);

		for (int i = 0; i < count; ++i) {
			if (word[i] != next_word[i]) {
				count = i;
				break;
			}
		}
	}

	std::cout << word.substr(0, count);
}

int main() {
	int n;
	std::cin >> n;
	FindMaxPrefix(n);
}