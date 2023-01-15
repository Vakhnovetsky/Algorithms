#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> cost;
	std::vector<int> weight;

	cost.push_back(0);
	weight.push_back(0);

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

	for (int i = 0; i < n; ++i) {
		int w, c;
		std::cin >> w >> c;
		weight.push_back(w);
		cost.push_back(c);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j - weight[i] >= 0) {
				dp[i][j] = std::max(dp[i - 1][j], cost[i] + dp[i - 1][j - weight[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	std::vector<int> answer;

	int i = n;
	int j = m;
	while (dp[i][j] > 0) {
		if (dp[i][j - 1] == dp[i][j]) {
			--j;
		}
		else if (dp[i - 1][j] == dp[i][j]) {
			--i;
		}
		else {
			answer.push_back(i);
			j -= weight[i];
			--i;
		}
	}

	std::cout << answer.size() << '\n';
	for (int i: answer) {
		std::cout << i << ' ';
	}
}