#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> buttons{ "abc",
									"def",
									"ghi",
									"jkl",
									"mno",
									"pqrs",
									"tuv",
									"wxyz" };

void Gererate(std::string& line, int n, std::string res){
	if (n == line.size()) {
		std::cout << res << " ";
		return;
	}

	for (char ch : buttons[line[n] - '2']) {
		Gererate(line, n + 1, res + ch);
	}
}

int main() {
	std::string line;
	std::cin >> line;

	Gererate(line, 0, "");
}