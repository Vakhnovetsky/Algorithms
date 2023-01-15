#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> digits;

	for (int i = 0; i < n; ++i) {
		string digit;
		cin >> digit;
		digits.push_back(digit);
	}

	sort(digits.begin(), digits.end(), [](string left, string right) {
		return (std::stoi(left + right) > std::stoi(right + left));
	});

	for (string& digit : digits) {
		cout << digit;
	}
}