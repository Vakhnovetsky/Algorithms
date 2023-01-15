/*
Задача. A. Пирамидальная сортировка
Описание.
Реализация пирамидальной сортировки с использованием собственной реализации приоритетной очереди (бинарной кучи).

ВРЕМЕННАЯ СЛОЖНОСТЬ
Приоритеная очередь реализована с использованием std::vector.

Вставка элемента в кучу осуществляется в конец вектора. Вставка в конец обычно имеет константную сложность О(1), в редком случае, когда нужно перевыделить память под вектор О(n).
После для восстановления свойств кучи проводится операция просеивания вверх, при которой на каждом уровне дерева проводится одно сравнение.
Таким образом сложность в худшем случае без учета сложности сравнения и перевыделения памяти в векторе: 
O(h), где h - высота дерева или 
O(log n), где n - количество узлов в дереве. 

Удаление элемента из кучи осущестляется "переносом" последнего элемента дерева в корень, что осуществляется за константную сложность О(1).
Далее для восстановления свойств кучи проводится операция просеивания вниз, при которой на каждом уровне дерева проводится максимально два сравнения.
Таким образом сложность в худшем случае без учета сложности сравнения: 
O(h), где h - высота дерева или 
O(log n), где n - количество узлов в дереве. 

Отдельно стоит рассмотреть сложность сравнения. 
Поскольку сравниваемые элементы являются структурой, состоящей из двух чисел типа int и сроки(string), то в худшем случае на каждом шаге 
происходит сравнение строк глубиной до минимальной длины строки из двух сравниваемых строк.
С учетом сравнения:
- для вставки элемента в среднем сложность составит O(m * log n), где n - количество узлов в дереве, m - средняя длина строки;
- для удаления элемента в среднем среднем сложность составит O(2* m * log n), где n - количество узлов в дереве, m - средняя длина строки.

Поскольку алгоритм пирамидальной сортировки заключается в поэлементной вставке всех элементов из неотсортированного массива в бинарную кучу,
а после поэлентное удаление всех элементов из кучи, то итоговая сложность такого алгоритма, учитывая сложность вставки и удаления составит 
O(m * log n), где n - количество элементов сортируемого массива, m - средняя длина строки из структуры элемента массива

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
В соответствии с алгоритмом происходит выделение дополнительной памяти под заполнение бинарной кучи всеми элементами из неотсортированного массива. 
Таким образом происходит выделение дополнительной памяти O(n), где n - количество элементов сортируемого массива. 
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

template<class T>
class PriorityQueue {
public:
	PriorityQueue(std::function<bool(const T&, const T&)> comp)
		: comp_(comp)
		, size_(0)
		, heap_(1) {
	}

	void Push(const T& item) {
		heap_.push_back(item);
		++size_;
		SiftUp();
	}

	void Pop() {
		if (!Empty()) {
			heap_[1] = heap_[size_];
			heap_.pop_back();
			--size_;
			SiftDown();
		}
	}

	T Top() const {
		return heap_.at(1);
	}

	int Size() const {
		return size_;
	}

	bool Empty() const {
		return  size_ == 0;
	}

private:
	std::vector<T> heap_;
	int size_;
	std::function<bool(const T&, const T&)> comp_;

	void SiftUp() {
		int idx = Size();
		while (true)
		{
			if (idx == 1) {
				break;
			}

			if (comp_(heap_[idx], heap_[idx / 2])) {
				std::swap(heap_[idx], heap_[idx / 2]);
				idx /= 2;
			}
			else {
				break;
			}
		}
	}

	void SiftDown() {
		int idx = 1;
		while (true) {
			if (heap_.size() > 2 * idx + 1) {
				if (comp_(heap_[2 * idx], heap_[2 * idx + 1])) {
					if (comp_(heap_[2 * idx], heap_[idx])) {
						std::swap(heap_[2 * idx], heap_[idx]);
						idx = 2 * idx;
					}
					else {
						break;
					}
				}
				else {
					if (comp_(heap_[2 * idx + 1], heap_[idx])) {
						std::swap(heap_[2 * idx + 1], heap_[idx]);
						idx = 2 * idx + 1;
					}
					else {
						break;
					}
				}
			}
			else if (heap_.size() == 2 * idx + 1 && comp_(heap_[2 * idx], heap_[idx])) {
				std::swap(heap_[2 * idx], heap_[idx]);
				break;
			}
			else {
				break;
			}
		}
	}
};

struct Participant {
	std::string name;
	int tasks;
	int penalty;
};

bool operator>(const Participant& lhs, const Participant& rhs) {
	return std::tuple<int, int, std::string_view>(lhs.tasks * -1, lhs.penalty, lhs.name) < std::tuple<int, int, std::string_view>(rhs.tasks * -1, rhs.penalty, rhs.name);
}

template<class T>
std::vector<T> Heapsort(std::vector<T>& array) {
	PriorityQueue<T> queue([](const T& lhs, const T& rhs) { return lhs > rhs; });

	for (const auto& item : array) {
		queue.Push(item);
	}

	std::vector<T> sorted_array;

	while (!queue.Empty()) {
		sorted_array.push_back(queue.Top());
		queue.Pop();
	}

	return sorted_array;
}

int main() {
	int n;
	std::vector<Participant> participants;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::string name;
		int tasks, penalty;
		std::cin >> name >> tasks >> penalty;
		participants.push_back({ name, tasks, penalty });
	}

	std::vector<Participant> sorted_participants = Heapsort<Participant>(participants);

	for (const auto& participant: sorted_participants) {
		std::cout << participant.name << '\n';
	}
}