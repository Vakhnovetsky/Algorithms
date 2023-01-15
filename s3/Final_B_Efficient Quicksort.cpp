/*
Задача. Эффективная быстрая сортировка.

Описание.

Реализация варианта быстрой сортировки модификации in-place со случайным выбором опорного элемента.

ВРЕМЕННАЯ СЛОЖНОСТЬ
В худшем случае количество сравнений O(n^2). Такое количество может быть достигнуто в случае, когда на каждом шаге
сравнения элементов подмассива с опорным (pivot) будет выбран максимально неудачный опорный элемент в результате чего подмассив
будет уменьшаться на один элемент. Т.е., например, в подмассиве n элементов и только один из них больше pivot, 
тогда на следующем шаге размер подмассива будет n-1. 
На практике такой вариант почти невозможет за счет случайного выбора опорного элемента из подмассива. 
Таким образом в среднем количество сравнений будет O(n log n) как и в лучшем случае.
Поскольку элемент массива является структурой, состоящей из двух чисел типа int и сроки(string), то в худшем случае на каждом шаге 
происходит сравнение строк глубиной до минимальной длины строки из двух сравниваемых строк.
Итоговая оценка с учетом сравнения строк получается O(m*n log n), где m - средняя длина строки. 

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
В модификации in-place быстрой сортировки в отличие от обычной не расходует дополнительную память при делении подмассива на две части.
Передача сортируемого массива в функцию quicksort осуществляется по ссылке, что позволяет не выделять дополнительную память под копируемый массив.
На каждом шаге проиходит выделение дополнительной памяти только под опорный элемент pivot. 
Таким образом в худжем случае происходит выделение дополнительной памяти O(n), в среднем O(log n).
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

struct Member {
	int tasks;
	int penalty;
	std::string login;
};

std::tuple<int, int, std::string_view> CreateTuple(const Member& member) {
	return std::tuple<int, int, std::string_view>(member.tasks, member.penalty, member.login);
}

bool operator<(const Member& lh, const Member& rh) {
	return CreateTuple(lh) < CreateTuple(rh);
}

bool operator==(const Member& lh, const Member& rh) {
	return CreateTuple(lh) == CreateTuple(rh);
}

bool operator>(const Member& lh, const Member& rh) {
	return rh < lh;
}

bool operator<=(const Member& lh, const Member& rh) {
	return !(lh > rh);
}

void quicksort(std::vector<Member>& array, int begin, int end) {
	if (end - begin > 1) {
		Member pivot = array[begin + rand() % (end - begin)];
		int p_left = begin;
		int p_right = end;

		while (p_left <= p_right) {
			while (p_left <= p_right && array[p_left] <= pivot) {
				++p_left;
			}

			while (p_left <= p_right && array[p_right] > pivot) {
				--p_right;
			}

			if (p_left < p_right && array[p_right] < array[p_left]) {
				std::swap(array[p_right], array[p_left]);
				++p_left;
				--p_right;
			}
		}

		quicksort(array, begin, p_left - 1);
		quicksort(array, p_left, end);
	}
	else if (end - begin == 1 && array[end] < array[begin]) {
		std::swap(array[end], array[begin]);
	}
}

int main() {
	int n;
	std::cin >> n;

	std::vector<Member> members(n);

	for (Member& member : members) {
		std::cin >> member.login >> member.tasks >> member.penalty;
		member.tasks *= -1;
	}

	quicksort(members, 0, members.size() - 1);

	for (const Member& member : members) {
		std::cout << member.login << '\n';
	}
}