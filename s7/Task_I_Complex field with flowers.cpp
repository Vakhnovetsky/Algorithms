#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
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

			if (i == 1 && j == 1) {
				dp[i][j] = points[i - 1][j - 1];
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + points[i - 1][j - 1];
			}
			
		}
	}

	std::string path;

	int i = n;
	int j = m;
	while (i > 1 || j > 1) {
		if (i > 1 && j > 1) {
			if (dp[i][j-1] > dp[i-1][j]) {
				--j;
				path += 'R';
			}
			else {
				--i;
				path += 'U';
			}
		}
		else if (i == 1) {
			--j;
			path += 'R';
		}
		else {
			--i;
			path += 'U';
		}
	}

	std::cout << dp[n][m] << '\n';
	for (int i = path.size() - 1; i >= 0; --i) {
		std::cout << path[i];
	}
}