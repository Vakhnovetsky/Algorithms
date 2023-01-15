#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Print(vector<int>& massiv) {
	for (int item : massiv) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> massiv;

	for (int i = 0; i < n; ++i) {
		int item;
		cin >> item;
		massiv.push_back(item);
	}
	int nn = n;
	int flag = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < nn - 1; ++j) {
			if (massiv[j] > massiv[j + 1]) {
				flag = 3;
				int temp = massiv[j];
				massiv[j] = massiv[j + 1];
				massiv[j + 1] = temp;
			}
		}
		if (flag == 2) {
			break;
		}
		Print(massiv);
		if (flag == 1) {
			break;
		}
		--nn;
		flag = 2;
	}
}