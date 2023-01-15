#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

int Solution(const Node* root) {
    int res = 1;
    if (!root->left && !root->right) {
        return res;
    }
    else{
        int res_left = 0;
        int res_right = 0;
        if (root->left) {
            res_left = Solution(root->left);
        }
        if (root->right) {
            res_right = Solution(root->right);
        }

        res += std::max(res_left, res_right);
    }
    return res;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ 4, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 8, nullptr, nullptr });
    Node node5({ 5, &node3, &node4 });
    assert(Solution(&node5) == 3);
}


int main() {
    test();
}
#endif