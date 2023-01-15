/*
Задача: A.Расстояние по Левенштейну
Описание. 
Даны две строки: s1 и s2.
n - количество элементов строки s1;
k - количество элементов строки s2.

Поскольку при вычислении очередной строки dp предыдущая строка становится ненужна, можно использовать одномерную динамику.
Для экономии памяти находим строку с меньшим количеством символов size = min(s1.size, s2.size)
Соответственно размер массива dp равен size

Базовый случай
При i = [0...size]
dp[i] = size

Переход динамики
Предыдущий массив dp сохраняем в prev_dp
prev_dp = dp
dp[0] = i
Для j[1...size]
dp[j] равен минимальному из трех:
min(
	dp[j - 1] + 1
	prev_dp[j] + 1
	prev_dp[j - 1] + m(s1[i - 1], s2[j - 1])
)
где  m(s1[i - 1], s2[j - 1]) = 0, если s1[i - 1] == s2[j - 1],
в противном случае m(s1[i - 1], s2[j - 1]) = 1.

ВРЕМЕННАЯ СЛОЖНОСТЬ
O(n*k),
где n - количество элементов строки 1;
k - количество элементов строки 2.

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
O(size),
где size - количество элементов наименьшей строки;
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	if (s2.size() > s1.size()) {
		s1.swap(s2);
	}

	std::vector<int> dp(s2.size() + 1);

	std::iota(dp.begin(), dp.end(), 0);

	std::vector<int> prev_dp;

	for (int i = 1; i <= s1.size(); ++i) {
		prev_dp = dp;
		dp[0] = i;
		for (int j = 1; j <= s2.size(); ++j) {
			dp[j] = std::min({ dp[j - 1] + 1, prev_dp[j] + 1, prev_dp[j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
		}
	}

	std::cout << dp[s2.size()];
}