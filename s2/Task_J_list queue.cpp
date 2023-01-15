#include <cassert>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node(int value, Node* next)
        : value(value)
        , next(next)
    {}
    int value;
    Node* next;
};

class Queue {
public:
	void size() {
		cout << size_ << "\n";
	}

	void put(int x) {
		Node* node = new Node(x, nullptr);
		if (size_ != 0) {
			tail_->next = node;
			
		}
		else {
			head_ = node;
		}
		tail_ = node;
		++size_;
	}

	void get() {
		if (size_ == 0) {
			cout << "error\n";
		}
		else {
			cout << head_->value << "\n";
			Node* node = head_;
			head_ = head_->next;
			delete node;
			--size_;
			if (size_ == 0) {
				tail_ = nullptr;
			}
		}
	}

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int size_ = 0;
};

int main() {
	int num_command;
	cin >> num_command;
	std::string command;
	Queue queue;

	for (int i = 0; i < num_command; ++i) {
		cin >> command;
		if (command == "size") {
			queue.size();
		}
		else if (command == "put") {
			int item;
			cin >> item;
			queue.put(item);
		}
		else if (command == "get") {
			queue.get();
		}
	}
}