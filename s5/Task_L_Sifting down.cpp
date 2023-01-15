#include <algorithm>
#include <vector>
#include <cassert>

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

int siftDown(std::vector<int>& heap, int idx) {
    while (true) {
        if (heap.size() > 2 * idx + 1) {
            if (heap[2 * idx] > heap[2 * idx + 1]) {
                if (heap[2 * idx] > heap[idx]) {
                    std::swap(heap[2 * idx], heap[idx]);
                    idx = 2 * idx;
                }
                else {
                    return idx;
                }
            }
            else {
                if (heap[2 * idx + 1] > heap[idx]) {
                    std::swap(heap[2 * idx + 1], heap[idx]);
                    idx = 2 * idx + 1;
                }
                else {
                    return idx;
                }
            }
        }
        else if (heap.size() == 2 * idx + 1 && heap[2 * idx] > heap[idx]) {
            std::swap(heap[2 * idx], heap[idx]);
            return 2 * idx;
        }
        else {
            return idx;
        }
    }
    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = { -1, 12, 1, 8, 3, 4, 7 };
    assert(siftDown(sample, 2) == 5);
}

int main() {
    test();
}
#endif