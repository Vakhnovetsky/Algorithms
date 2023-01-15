#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str;
	size_t a;
	size_t m;
	size_t num;
	std::cin >> a >> m >> str >> num;

	std::vector<uint64_t> vec;
	vec.push_back(1);
	vec.push_back(a);
	for (size_t i = 2; i <= str.size(); ++i) {
		vec.push_back((vec.back() * a) % m);
	}

	std::vector<uint64_t> hash;
	hash.push_back(0);
	for (size_t i = 0; i <= str.size(); ++i) {
		hash.push_back((hash.back() * a + str[i]) % m);
	}

	for (size_t i = 0; i < num; ++i) {
		size_t begin, end;
		std::cin >> begin >> end;

		std::cout << (hash[end] + m - (hash[begin - 1] * vec[end - begin + 1]) % m) % m << '\n';
	}
}