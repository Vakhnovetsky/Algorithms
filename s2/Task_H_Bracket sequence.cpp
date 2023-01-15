#include <iostream>
#include <stack>
#include <string>

int main() {
	std::string line;
	std::getline(std::cin, line);

	std::stack<char> st;

	for(char ch: line){
    	switch(ch) {
        case '{': st.push('}'); break;
        case '[': st.push(']'); break;
        case '(': st.push(')'); break;
        case '}': 
        	if(!st.empty() && st.top() == '}'){
            	st.pop();
            	break;
        	}
        	else {
            	std::cout << "False";
            	return 0;
            }
        case ']':
        	if(!st.empty() && st.top() == ']'){
            	st.pop();
            	break;
        	}
        	else {
            	std::cout << "False";
            	return 0;
            }
        case ')':
        	if(!st.empty() && st.top() == ')'){
            	st.pop();
            	break;
        	}
        	else {
            	std::cout << "False";
            	return 0;
            }
    	}
	}

	if(st.empty()) {
    	std::cout << "True";
	}
	else{
    	std::cout << "False";
	}	
}