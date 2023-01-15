#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main() {
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream(line);
	std::vector<std::string> text;

	for(auto iter = std::istream_iterator<std::string>(stream); iter != std::istream_iterator<std::string>(); ++iter) {
    	text.push_back(*iter);
    }

	for(int i = text.size() - 1; i >= 0; --i){
    	std::cout << text[i] << ' ';
	}
}