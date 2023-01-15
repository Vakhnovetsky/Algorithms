/*
Задача. Хеш-таблица.

Описание.
Реализация хеш-таблицы с методами Put, Get и Delete. Коллизии разрешаются методом цепочек.

ВРЕМЕННАЯ СЛОЖНОСТЬ
В среднем методы Put, Get и Delete выполняются за константное время O(1).
В худшем случае при коллизии методы Put, Get и Delete выполняются за O(m), где m - количество элементов в корзине (basket)

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
По условию задачи количество ключей в хеш-таблице не может превышать 10^5.
Выделение памяти под хранение элементов происходит в конструкторе. Таким образом при создании объекта класса сразу на всю таблицу происходит выделение памяти O(n),
где n - максимальное количество ключей. 
Возможно выделение дополнительной памяти для хранения элементов при разрешении коллизии. В этом случае в такой корзинке выделяется память под еще один элемент списка list.
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <vector>
#include <utility>

class MyMap {
public:
	MyMap() :buskets_(100000)
	{}

	void Put(int key, int value) {
		int hash = GetHashNumber(key);
		auto iter = FindElement(hash, key);

		if (iter != buskets_.at(hash).end()) {
			iter->second = value;
		}
		else {
			buskets_[hash].push_front({ key, value });
		}
	}

	std::optional<int> Get(int key) {
		std::optional<int> value;
		int hash = GetHashNumber(key);
		auto iter = FindElement(hash, key);

		if (iter != buskets_.at(hash).end()) {
			value = iter->second;
		}
		return value;
	}

	std::optional<int> Delete(int key) {
		std::optional<int> value;
		int hash = GetHashNumber(key);
		auto iter = FindElement(hash, key);

		if (iter != buskets_.at(hash).end()) {
			value = iter->second;
			buskets_[hash].erase(iter);
		}
		return value;
	}

private:
	std::vector<std::list<std::pair<int, int>>> buskets_;

	int GetHashNumber(int key) {
		return key % 100000;
	}

	std::list<std::pair<int, int>>::iterator FindElement(int hash, int key) {
		return std::find_if(buskets_.at(hash).begin(), buskets_.at(hash).end(), [key](auto& el) {return el.first == key; });
	}
};

void Print(std::optional<int> value) {
	if (value.has_value()) {
		std::cout << value.value() << '\n';
	}
	else {
		std::cout << "None" << '\n';
	}
}

int main() {
	int n;
	std::cin >> n;

	MyMap hash_table;

	for (int i = 0; i < n; ++i) {
		std::string command;
		std::cin >> command;
		int key;
		std::cin >> key;
		if (command == "get") {
			Print(hash_table.Get(key));
		}
		else if (command == "put") {
			int value;
			std::cin >> value;
			hash_table.Put(key, value);
		}
		else if (command == "delete") {
			Print(hash_table.Delete(key));
		}
	}
}