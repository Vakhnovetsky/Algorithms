/*
Задача: B. Шпаргалка
Описание. 
Дан текст text и множество слов (словарь). 
Надо проверить можно ли разбирать данный текст на слова из множества

Слова из словаря добавляем в префиксное дерево (бор).
Таким образом сможем работать одновренменно со всем множеством слов.
Для поиска слов в тексте используем динамическое программирование

Базовый случай
dp[0] = true

Переход динамики
Для i[1...size(text)]
dp[i] равен true если:
- найдено в тексте слово из множества длины L 
- dp[i-L] равно true

ВРЕМЕННАЯ СЛОЖНОСТЬ
Сложность поиска слова в боре зависит от способа хранения ребер. 
В данном решении ребра хранятся в std::unordered_map, поэтому сложность в среднем будет
O(L), где L - длина слова
Сложность построения бора O(Lsum), где Lsum - суммарная длина слов во множестве
Сложность проверки разбития текста на слова O(size^2)
где size - количество символов в тексте

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Требуется память для хранения dp:
O(size), где size - количество символов в тексте
и префиксного дерева:
O(Lsum), где Lsum - суммарная длина слов во множестве
*/

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std::string_view_literals;

struct Node {
	std::unordered_map<char, std::shared_ptr<Node>> list;
	bool is_terminal = false;
};

void AddWordToTree(std::shared_ptr<Node> root, std::string_view word) {
	std::shared_ptr<Node> current_node = root;

	for (char ch: word) {
		if (current_node->list.find(ch) == current_node->list.end()) {
			std::shared_ptr<Node> new_node(new Node);
			current_node->list[ch] = new_node;
			current_node = new_node;
		}
		else {
			current_node = current_node->list[ch];
		}
	}

	current_node->is_terminal = true;
}

int main() {
	std::string text;
	int n;
	std::shared_ptr<Node> root(new Node);

	std::cin >> text >> n;
	for (int i = 0; i < n; ++i) {
		std::string word;
		std::cin >> word;
		AddWordToTree(root, word);
	}

	std::vector<bool> dp(text.size() + 1);
	dp[0] = true;

	for (int i = 1; i <= dp.size(); ++i) {
		std::shared_ptr<Node> current_node = root;
		int pos = i - 1;
		if (dp[pos]) {
			while (pos < text.size()) {
				auto iter = current_node->list.find(text[pos]);
				if (iter != current_node->list.end()) {
					current_node = current_node->list[text[pos]];
					++pos;
					if (current_node->is_terminal) {
						dp[pos] = true;
					}
				}
				else {
					break;
				}
			}
		}
	}

	std::cout << (dp.back() ? "YES"sv : "NO"sv);
}