#include <algorithm>
#include <iostream>
#include <string>

int main() {
	std::string num1, num2;
	std::cin >> num1 >> num2;
	std::string res;

	bool mem = false;

	if (num1 == "0") {
		std::cout << num2;
		return 0;
	}

	if (num2 == "0") {
		std::cout << num1;
		return 0;
	}

	int i = num1.size() - 1;
	int j = num2.size() - 1;

	while (i != -1 || j != -1) {
		if (i == -1) {
			if (mem) {
				if (num2[j] == '0') {
					res += '1';
					mem = false;
				}
				else {
					res += '0';
				}
			}
			else {
				res += num2[j];
			}
			
			--j;
			continue;
		}

		if (j == -1) {
			if (mem) {
				if (num1[i] == '0') {
					res += '1';
					mem = false;
				}
				else {
					res += '0';
				}
			}
			else {
				res += num1[i];
			}
			
			--i;
			continue;
		}

		if (num1[i] == '0' && num2[j] == '0') {
			if (mem) {
				res += '1';
				mem = false;
			}
			else {
				res += '0';
			}	
		}
		else if (num1[i] == '0' && num2[j] == '1' || num1[i] == '1' && num2[j] == '0') {
			if (mem) {
				res += '0';
			}
			else {
				res += '1';
			}
		}
		else if (num1[i] == '1' && num2[j] == '1') {
			if (mem) {
				res += '1';
			}
			else {
				res += '0';
				mem = true;
			}
		}
		else {
			std::cout << "!!!!";
		}
		--j;
		--i;
	}

	if (mem) {
		res += '1';
	}

	std::reverse(res.begin(), res.end());
	std::cout << res;
}