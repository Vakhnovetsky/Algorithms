#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class MyQueueSized {
public:
	MyQueueSized(int max_size)
		: max_size_(max_size)
		, vec_(max_size){
	}

	void push(int x) {
		if (size_ == max_size_) {
			cout << "error\n";
		}
		else {
			vec_[tail_] = x;
			++tail_;
			++size_;
			if (tail_ == max_size_) {
				tail_ = 0;
			}
		}
	}

	void pop() {
		if (is_empty()) {
			cout << "None\n";
		}
		else {
			cout << vec_[head_] << "\n";
			++head_;
			--size_;
			if (head_ == max_size_) {
				head_ = 0;
			}
		}
	}

	bool is_empty() {
		return size_==0;
	}

	void peek() {
		if (is_empty()) {
			cout << "None\n";
		}
		else {
			cout << vec_[head_] << "\n";
		}
	}

	void size() {
		cout << size_ << "\n";
	}

private:
	int size_ = 0;
	int head_ = 0;
	int tail_ = 0;
	int max_size_;
	vector<int> vec_;
};

int main() {
	int num, num_command;
	cin >> num_command >> num;
	std::string command;
	MyQueueSized queue(num);

	for (int i = 0; i < num_command; ++i) {
		cin >> command;
		if (command == "size") {
			queue.size();
		}
		else if (command == "push") {
			int item;
			cin >> item;
			queue.push(item);
		}
		else if (command == "pop") {
			queue.pop();
		}
		else if (command == "peek") {
			queue.peek();
		}
	}
}