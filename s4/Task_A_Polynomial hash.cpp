#include <iostream>
#include <string>

int main()
{
	std::string str;
	int q;
	int R;

	std::cin >> q >> R >> str;
	uint64_t res = 0;

	for (char ch : str) {
		res = (res * q + (int)(ch)) % R;
	}
	std::cout << res;
}