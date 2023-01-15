/*
Задача. Поисковая система.

Описание.
Реализация поиской системы.
Класс SearchServer содержит два публичных метода: AddDocuments для добавления документов и FindTopDocuments для нахождения пяти наиболлее релевантных документов
в соответствии с запросом. Для хранения данных о добавленных документах используется хеш-таблица unordered_map.

ВРЕМЕННАЯ СЛОЖНОСТЬ
AddDocuments выполняется за O(m*k), где 
m - количество слов в документе,
k - среднее количество символов в слове. 

Время выполнения FindTopDocuments завист как от количества слов в запросе, так и от количетства добавленных слов и документов, среди которых нужно искать релевантные запросу:
O(m*k), где
m - количество уникальных слов в запросе,
k - среднее количество добавленных документов, в которых есть в наличии слово.

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Память под хранение документов выделяется при выполнении метода AddDocuments.
Суммарно размер выделенной памяти зависит от количества уникальных слов во всех добавленных документах и количества документов, в которых это слово упоминается.
Размер выделенной памяти можно оценить как O(m*k), где
m - количество уникальных слов во всех документах,
k - среднее количество добавленных документов, в которых есть в наличии слово.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Document {
	int id;
	int rating;
};

class SearchServer {
public:
	SearchServer() = default;

	void AddDocuments(int id, std::string& line) {
		std::istringstream stream(line);

		auto iter_end = std::istream_iterator<std::string>();
		for (auto iter = std::istream_iterator<std::string>(stream); iter != iter_end; ++iter) {
			--word_to_document_rating_[*iter][id];
		}
	}

	std::vector<Document> FindTopDocuments(std::string& query) const {
		std::vector<Document> documents;
		std::unordered_map<int, int> ids;

		std::istringstream stream(query);

		std::istream_iterator iter = std::istream_iterator<std::string>(stream);
		std::unordered_set<std::string> words(iter, std::istream_iterator<std::string>());

		for (const auto& word : words) {
			if (word_to_document_rating_.find(word) != word_to_document_rating_.end()) {
				for (const auto document_rating: word_to_document_rating_.at(word)) {
					ids[document_rating.first] += document_rating.second;
				}
			}
		}

		for (const auto& id: ids) {
			documents.push_back({ id.first, id.second });
		}

		std::sort(documents.begin(), documents.end(), [](const Document& lhs, const Document& rhs) {
			return std::tuple{ lhs.rating, lhs.id } < std::tuple{ rhs.rating, rhs.id }; });

		if (documents.size() > 5) {
			documents.resize(5);
		}

		return documents;
	}

private:
	std::unordered_map<std::string, std::unordered_map<int, int>> word_to_document_rating_;
};

int main() {
	int n;
	std::string line;
	SearchServer server;

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::getline(std::cin >> std::ws, line);
		server.AddDocuments(i + 1, line);
	}

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::getline(std::cin >> std::ws, line);
		std::vector<Document> documents = server.FindTopDocuments(line);
		for (const Document& doc : documents) {
			std::cout << doc.id << ' ';
		}
		std::cout << '\n';
	}
}