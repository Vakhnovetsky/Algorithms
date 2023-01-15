#include <cmath>
#include <iostream>

int Sum(int n, int k) {
	if (n == 0 || n == 1) {
    	
		return 1;
	}
	else {
		int old = 1;
		int res = 1;
		for (int i = 2; i <= n; ++i) {
			int temp = res;
			res = (res + old) % static_cast<int>(std::pow(10, k));
			old = temp;
		}
		return res;
	}
}

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout <<  Sum(n, k);
}