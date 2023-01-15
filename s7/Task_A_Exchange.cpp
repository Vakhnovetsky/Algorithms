#include <iostream>

int main() {
	int n;
	std::cin >> n;

	bool is_bought = false;
	int last = -1;
	int price_bought = -1;
	int res = 0;

	for (int i = 0; i < n; ++i) {
		int price;

		std::cin >> price;
		if (last == -1) {
			last = price;
		}
		else {
			if (!is_bought && last < price) {
				price_bought = last;
				last = price;
				is_bought = true;
			}
			else if (!is_bought && price < last || is_bought && last < price) {
				last = price;
			}
			else if (is_bought && price < last) {
				res += (last - price_bought);
				is_bought = false;
				last = price;
			}
		}
	}

	if (is_bought) {
		res += (last - price_bought);
	}

	std::cout << res;
}