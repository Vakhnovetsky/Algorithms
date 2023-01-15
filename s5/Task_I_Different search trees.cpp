#include <iostream>

uint64_t increase(int begin, int end)
{
	uint64_t f = 1;
	for (int i = begin; i <= end; ++i)
	{
		f *= i;
	}
	return f;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << increase(n + 2, 2 * n) / increase(1, n);
}