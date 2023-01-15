#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int64_t> dp;
	int mod = 1000000007;

	dp.push_back(1);
	dp.push_back(1);

	for (int i = 2; i <= n; ++i) {
		dp.push_back((dp[i-1] + dp[i - 2]) % mod);
	}

	std::cout << dp.back();
}