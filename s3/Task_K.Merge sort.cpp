#include <iostream>
#include <vector>
#include <cassert>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
	CIterator left_begin, CIterator left_end,
	CIterator right_begin, CIterator right_end) {

	std::vector<int> result;

	while (left_begin != left_end && right_begin != right_end) {
		if (*left_begin <= *right_begin) {
			result.push_back(*left_begin);
			++left_begin;
		}
		else {
			result.push_back(*right_begin);
			++right_begin;
		}
	}

	while (left_begin != left_end) {
		result.push_back(*left_begin);
		++left_begin;
	}

	while (right_begin != right_end) {
		result.push_back(*right_begin);
		++right_begin;
	}

	return result;
}

void merge_sort(Iterator begin, Iterator end) {
	if (end - begin > 1) {
		Iterator mid = begin + (end - begin) / 2;
		merge_sort(begin, mid);
		merge_sort(mid, end);
		auto res = merge(begin, mid, mid, end);

		Iterator b = res.begin();
		while (begin != end) {
			*begin = *b;
			++b;
			++begin;
		}
	}
}

void test_merge_sort() {
	std::vector<int> a = { 1, 4, 9 };
	std::vector<int> b = { 2, 10, 11 };
	std::vector<int> c = merge(a.cbegin(), a.cend(), b.cbegin(), b.cend());
	std::vector<int> expected = { 1, 2, 4, 9, 10, 11 };
	assert(c == expected);
	std::vector<int> d = { 1, 4, 2, 10, 1, 2 };
	std::vector<int> sorted = { 1, 1, 2, 2, 4, 10 };
	merge_sort(d.begin(), d.end());
	assert(d == sorted);
}