#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class StackMaxEffective {
public:
	void push(int x) {
		if (vec_.empty() || x > max_.back()) {
			max_.push_back(x);
		}
		else {
			max_.push_back(max_.back());
		}

		vec_.push_back(x);
	}

	void pop() {
		if (vec_.empty()) {
			cout << "error\n";
		}
		else {
			vec_.pop_back();
			max_.pop_back();
		}
	}

	void get_max() {
		if (vec_.empty()) {
			cout << "None\n";
		}
		else {
			cout << max_.back() << "\n";
		}
	}

private:
	vector<int> max_;
	vector<int> vec_;
};

int main() {
	int num;
	cin >> num;
	std::string command;
	StackMaxEffective stack;

	for (int i = 0; i < num; ++i) {
		cin >> command;
		if (command == "get_max") {
			stack.get_max();
		}
		else if (command == "push") {
			int item;
			cin >> item;
			stack.push(item);
		}
		else if (command == "pop") {
			stack.pop();
		}
	}
}