#include <iostream>
#include <random>
#include <string>

int GetHash(std::string& str, int q = 1000, int R = 123987123) {
	uint64_t res = 0;
	for (char ch : str) {
		res = (res * q + (int)(ch)) % R;
	}
	return res;
}

void GetStringRandom(std::string& str, int n) {
	for (int i = 0; i < n; ++i) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6('a', 'z');
		str += dist6(rng);
	}
}

void NextSrting(std::string& str, int& pos) {
	if (str[pos] >= 'a' && str[pos] < 'z') {
		++str[pos];
	}
	else if (str[pos] == 'z') {
		int curr_pos = pos;
		while (str[curr_pos] == 'z' && curr_pos > 0) {
			str[curr_pos] = 'a';
			--curr_pos;
		}
		if (curr_pos == 0 && str[curr_pos] == 'z') {
			str[curr_pos] = 'a';
			str += 'a';
			pos = str.size() - 1;
		}
		else {
			++str[curr_pos];
		}
	}
}

int main()
{
	std::string str1, str2 = "aaa";
	int pos = str2.size() - 1;

	GetStringRandom(str1, 20);
	int hash1 = GetHash(str1);
	int hash2 = 0;

	while (hash1 != hash2) {
		NextSrting(str2, pos);
		hash2 = GetHash(str2);
	}

	std::cout << "str1=" << str1 << '\n' << "str2=" << str2 << '\n' << "hash1=" << hash1 << '\n' << "hash2=" << hash2;
}