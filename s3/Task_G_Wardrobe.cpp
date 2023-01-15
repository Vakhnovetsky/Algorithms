#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> result(3, 0);
	
	for(int i=0; i<n; ++i) {
		int dress;
		std::cin >> dress;
		++result[dress];
	}
	
	int color = 0;
	
	for(int clothes: result){
		for(int i=0; i<clothes; ++i) {
			std::cout << color << ' ';
		}
		++color;
	}
}