#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> temperature;
	temperature.reserve(n);

	for(int i=0; i<n; ++i) {
    	int temp;
    	std::cin >> temp;
    	temperature.push_back(temp);
	}

	if(n==1) {
    	std::cout << 1;
    	return 0;
	}

	int res=0;

	for(int i=0; i<n; ++i) {
    	if(i==0 && temperature[i]>temperature[i+1] || 
           i==n-1 && temperature[i]>temperature[i-1] || 
           i!=0 && i!=n-1 && temperature[i]>temperature[i+1] && temperature[i]>temperature[i-1]){
    		++res;
    	}
	}
	std::cout << res;
}