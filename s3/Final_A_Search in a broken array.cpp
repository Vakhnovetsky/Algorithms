/*
Задача. Поиск в сломанном массиве

Описание.
Реализация бинарного поиска в массиве, который состоит из двух отсортированных подмассивов.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Временная сложность как и в классическом бинарном поиске O(log n), где n - количество элементов массива.

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Передача сортируемого массива в функцию broken_search осуществляется по ссылке, что позволяет не выделять дополнительную память под копируемый массив. 
Таким образом простанственная сложность алгоритма O(n), где n - количество элементов массива.
*/

#include "solution.h"
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

int broken_search(const std::vector<int>& vec, int k) {
    int begin = 0;
    int end = vec.size()-1;

    while (begin < end) {
        int mid = (begin + end) / 2;

        if (vec[mid] == k) {
            return mid;
        }
        else if (vec[begin] > vec[end]) {
            if (vec[mid] >= vec[begin]) {
                if (vec[begin] <= k && k < vec[mid]) {
                    end = mid - 1;
                }
                else {
                    begin = mid + 1;
                }
            }
            else {
                if (vec[mid] < k && k <= vec[end]) {
                    begin = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        else {
            if (vec[mid] > k) {
                end = mid-1;
            }
            else {
                begin = mid+1;
            }
        }
    }

    if (vec[begin] == k) {
        return begin;
    }
    else {
        return -1;
    }
}

void test() {
	assert(6 == broken_search({ 19, 21, 100, 101, 1, 4, 5, 7, 12 }, 5));
	assert(1 == broken_search({ 5, 1 }, 1));
	assert(-1 == broken_search({ 0, 2, 6, 7, 8, 9, 10 }, 4));
	assert(-1 == broken_search({ 6, 7, 10, 0, 2, 4, 5 }, 3));
	assert(1 == broken_search({ 5, 1 }, 1));
	assert(-1 == broken_search({ 0, 2, 6, 7, 8, 9, 10 }, 5));
}