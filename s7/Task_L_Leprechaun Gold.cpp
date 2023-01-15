#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> weight;

	weight.push_back(0);

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

	for (int i = 0; i < n; ++i) {
		int w;
		std::cin >> w;
		weight.push_back(w);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j - weight[i] >= 0) {
				dp[i][j] = std::max(dp[i - 1][j], weight[i] + dp[i - 1][j - weight[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			
		}
	}

	std::cout << dp[n][m];
}