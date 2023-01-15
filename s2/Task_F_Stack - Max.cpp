#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StackMax {
public:
	void push(int x) {
		vec_.push_back(x);
	}

	void pop() {
		if (vec_.empty()) {
			cout << "error\n";
		}
		else {
			vec_.pop_back();
		}
	}

	void get_max() {
		if (vec_.empty()) {
			cout << "None\n";
		}
		else {
			int max = vec_.front();
			for (auto v : vec_) {
				if (v > max) {
					max = v;
				}
			}
			cout << max << "\n";
		}
	}

private:
	vector<int> vec_;
};

int main() {
	int num;
	cin >> num;
	std::string command;
	StackMax stack;

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