#include <iostream>
#include <string>

int main() {
	std::string word;
	std::getline(std::cin, word);

	int left=0;
	int right=word.size()-1;
	bool result = true;

	while(left < right) {
    	if(!std::isalnum(word[left])){
        	++left;
    	}
    	else if(!std::isalnum(word[right])){
        	--right;
    	}
		else if(std::toupper(word[left]) == std::toupper(word[right])) {
			++left;
            --right;
    	}
    	else {
        	result = false;
        	break;
    	}
	}

	std::cout << (result ? "True" : "False");
}