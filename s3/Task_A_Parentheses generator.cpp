#include <iostream>
#include <string>

void Gen(int n, int n2, std::string line) {
	if (n == 0 && n2 == 0) {
		std::cout << line << "\n";
		return;
	}

	if (n > 0) {
		Gen(n - 1, n2, line + '(');
	}

	if (n2 > 0 && n2 > n) {
		Gen(n, n2 - 1, line + ')');
	}	
}

int main() {
	int n;
	std::cin >> n;
	std::string line;

	Gen(n, n, line);
}