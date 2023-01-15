/*
Задача. Калькулятор с обратной польской нотацией. 

Описание.
Я реализовал калькулятор используя стек. 
При парсинге арифметического выражения все встречающиеся числа добавляются на вершину стека в порядке слева направо. 
Если встречается знак арифметической операции, то из стека забираются два последних числа, над ними проводится операция, результат которой обратно добавляется в стек.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Стоимость добавление и извлечение из стека зависит от реалиции самого стека в компиляторе. 
По стандарту Equal to the complexity of Container::pop_back и Equal to the complexity of Container::push_back
Скорее всего данные операции имеют константную сложность О(1).
Таким образом полное добавление и извлечение всех чисел из стека происходит за O(n).

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Добавление чисел в стек осуществляется в процессе парсинга. Максимальный размер стека может достигнуть общего количества чисел в выражении O(n).
*/

#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>

int main() {
	std::stack<int> operands;
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream(line);

	for (auto iter = std::istream_iterator<std::string>(stream); iter != std::istream_iterator<std::string>(); ++iter) {
		if (iter->size() > 1 || std::isdigit(iter->front())) {
			operands.push(std::stoi(*iter));
		}
		else {
			switch (iter->front())
			{
			case '+': {
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();
				operands.push(a + b);
				break;
			}
			case '-': {
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();
				operands.push(a - b);
				break;
			}
			case '*': {
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();
				operands.push(a * b);
				break;
			}
			case '/': {
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();
				operands.push(std::floor(a / static_cast<double>(b)));
				break;
			}
			}
		}
	}
	std::cout << operands.top();
}