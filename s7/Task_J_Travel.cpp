#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> A;
	std::vector<int> dp(n + 1);

	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		A.push_back(temp);
	}

	int res_max = 0;

	for (int i = 1; i <= n; ++i) {
		int max_val = 0;
		for (int j = 1; j <= n; ++j) {
			if (A[i - 1] == A[j - 1]) {
				dp[j] = std::max(dp[j], max_val + 1);
			}

			if (A[j - 1] < A[i - 1]) {
				max_val = std::max(max_val, dp[j]);
			}
		}
		res_max = std::max(res_max, dp[i]);
	}

	std::cout << res_max << '\n';

	std::vector<std::vector<int>> answer(dp.size() + 1);

	for (int i = 1; i <= n; ++i) {
		if (dp[i] == 1) {
			answer[i].push_back(i);
		}
		else {
			for (auto& ans : answer) {
				if (ans.size() == dp[i] - 1 && A[ans.back() - 1] < A[i - 1]) {
					answer[i].insert(answer[i].end(), ans.begin(), ans.end());
					answer[i].push_back(i);
					break;
				}
				else if (ans.size() == dp[i] && A[ans.back() - 1] > A[i - 1]) {
					if (ans.size() > 1) {
						if (A[ans[ans.size() - 2] - 1] < A[i - 1]) {
							ans[ans.size() - 1] = i;
						}
					}
					else {
						ans[ans.size() - 1] = i;
					}
				}
			}
		}
	}

	for (auto& ans : answer) {
		if (ans.size() == res_max) {
			for (int i : ans) {
				std::cout << i << ' ';
			}
			break;
		}
	}
}