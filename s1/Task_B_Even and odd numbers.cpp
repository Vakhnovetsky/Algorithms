#include <iostream>

int main() {
	int a, b, c;

	std::cin >> a >> b >> c;

	if(a%2==0 && b%2==0 && c%2==0 || a%2!=0 && b%2!=0 && c%2!=0) {
		std::cout << "WIN";
	}
	else {
		std::cout << "FAIL";
	}
}