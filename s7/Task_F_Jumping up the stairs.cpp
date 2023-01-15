#include <iostream>
#include <vector>

int main() {
	int n, k;
	int mod = 1000000007;
	int res = 0;

	std::cin >> n >> k;

	std::vector<int64_t> dp(n + 2);
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= k+1; ++i) {
		dp[i] = (dp[i - 1] * 2) % mod;
	}

	for (int i = k + 2; i <= n; ++i) {
		int j = i;
		while (i - j < k) {
			--j;
			dp[i] += dp[j];
			dp[i] = dp[i] % mod;
		}
	}

	std::cout << dp[n];
}