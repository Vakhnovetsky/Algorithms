#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> points(n, std::vector<int>(m));
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

	for (int i = n-1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			std::cin >> ch;
			points[i][j] = ch - '0';
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + points[i - 1][j - 1];
		}
	}

	std::cout << dp[n][m];
}