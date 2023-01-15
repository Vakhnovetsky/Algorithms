#include <iostream>

int main() {
	int num;
	std::cin >> num;

	while(num >= 4){
    	if(num % 4 == 0) {
        	num /= 4;
        }
    	else {
        	std::cout << "False";
        	return 0;
    	}
	}

	std::cout << (num == 1 ? "True" : "False");
}