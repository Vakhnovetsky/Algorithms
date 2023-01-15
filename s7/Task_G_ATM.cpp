#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> m >> n;
	std::vector<int> coins;
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

	coins.push_back(0);

	for (int i = 0; i < n; ++i) {
		int coin;
		std::cin >> coin;
		coins.push_back(coin);
	}

	for( int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j - coins[i] >= 0) {
				dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	std::cout << dp[n][m];
}