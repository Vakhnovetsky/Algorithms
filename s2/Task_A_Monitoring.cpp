#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> vec;

	for(int i = 0; i < n; ++i) {
    	vec.push_back({});
		for(int j = 0; j < m; ++j){
        	int temp;
        	std::cin >> temp;
			vec[i].push_back(temp);
        }
	}

	for(int j = 0; j < m; ++j){
    	for(int i = 0; i < n; ++i) {
        	std::cout << vec[i][j] << " ";
        }
    	std::cout << "\n";
    }
}