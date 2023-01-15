#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	std::vector<int> b;
	a.push_back(0);
	b.push_back(0);

	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		a.push_back(temp);
	}

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		b.push_back(temp);
	}

	std::vector<std::vector<int>> dp(a.size(), std::vector<int>(b.size()));

	for (int i = 1; i < a.size(); ++i) {
		for (int j = 1; j < b.size(); ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	std::cout << dp[a.size()-1][b.size()-1];

	if (dp[a.size() - 1][b.size() - 1] > 0) {
		std::vector<int> answer_a;
		std::vector<int> answer_b;
		int i = a.size() - 1;
		int j = b.size() - 1;

		while (dp[i][j] > 0) {
			if (a[i] == b[j]) {
				answer_a.push_back(i);
				answer_b.push_back(j);
				--i;
				--j;
			}
			else {
				if (dp[i][j] == dp[i - 1][j]) {
					--i;
				}
				else {
					--j;
				}
			}
		}

		std::cout << '\n';

		for (int i = answer_a.size() - 1; i >= 0; --i) {
			std::cout << answer_a[i] << ' ';
		}
		std::cout << '\n';

		for (int i = answer_b.size() - 1; i >= 0; --i) {
			std::cout << answer_b[i] << ' ';
		}
	}	
}