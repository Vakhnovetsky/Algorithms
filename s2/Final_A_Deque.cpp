/*
Задача. Реализуйте Дек используя кольцевой буфер.

Описание.
Я реализовал Дек с использованием массива(vector) и индексами начала и конца.
При создании объекта deque внутри инициализируется вектор фиксированного размера (max size), который используется в качестве буфера.
На начало и конец дека указывают индексы head_ и tail_.
Добавление в конец осуществляется на индекс tail_, после чего индекс сдвигается на 1 вправо. Если индекс достиг конца массива, то перескакивает на начало.
Добавление в начало осуществляется на индекс head_-1, т.е. индекс сначала сдвигается на 1 влево, в потом на него идет добавление. Если индекс достиг начала массива, то перескакивает на конец.
 
При попытке добавить в полностью заполненный дек (size_ == max_size_) в поток выводится error

При взятии элемента с начала дека осуществляется вывод с индекса head_, после чего индекс сдвигается на 1 вправо. 
При взятии элемента с конца дека индекс tail_ сначал сдвигается на 1 влево, после осуществляется вывод с получившегося значения.

За счет перескакивания индекса при добавлении и извлечения элемента осуществляется кольцевание буфера.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Благодаря наличию индексов как на начало так и на конец вектора добавление и удаление одного элемента стоит О(1), поскольку доступ к элементу верктора по индеску осущестляется за константную сложность.
Таким образом добавление и извлечение n элементов в сумме будет стоить O(n).

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Выделение памяти на максимальное количество элементов дека происходит при создании объекта. Таким образом буфер дека всегда занимает О(n).
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyDeque {
public:
	MyDeque(int max_size) 
		: max_size_(max_size)
		, vec_(max_size, 0) {
	}

	void push_back(int value) {
		if (max_size_ == size_) {
			cout << "error\n";
			return;
		}

		vec_[tail_] = value;
		tail_ = (tail_ + 1) % max_size_;
		++size_;
	}

	void push_front(int value) {
		if (max_size_ == size_) {
			cout << "error\n";
			return;
		}

		head_ = (head_ - 1 + max_size_) % max_size_;
		vec_[head_] = value;
		++size_;
	}

	void pop_front() {
		if (size_ == 0) {
			cout << "error\n";
		}
		else {
			cout << vec_[head_] << "\n";
			head_ = (head_ + 1) % max_size_;
			--size_;
		}
	}

	void pop_back() {
		if (size_ == 0) {
			cout << "error\n";
		}
		else {
			tail_ = (tail_ - 1 + max_size_) % max_size_;
			cout << vec_[tail_] << "\n";
			--size_;
		}
	}

private:
	std::vector<int> vec_;
	int head_ = 0;
	int tail_ = 0;
	int size_ = 0;
	int max_size_;
};

int main() {
	int num_command, m;
	cin >> num_command >> m;
	std::string command;
	MyDeque deque(m);

	for (int i = 0; i < num_command; ++i) {
		cin >> command;
		if (command == "push_back") {
			int value;
			cin >> value;
			deque.push_back(value);
		}
		else if (command == "push_front") {
			int value;
			cin >> value;
			deque.push_front(value);
		}
		else if (command == "pop_front") {
			deque.pop_front();
		}
		else if (command == "pop_back") {
			deque.pop_back();
		}
	}
}