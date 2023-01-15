#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

void print_range(Node* root, int l, int r) {

    if (root->left && (root->left->value >=l || root->left->value < l && root->left->right)) {
        print_range(const_cast<Node*>(root->left), l, r);
    }

    if (root->value == l || root->value == r || l < root->value && root->value < r) {
        cout << root->value << ' ';
    }

    if (root->right && (root->right->value <= r || root->right->value > r && root->right->left)) {
        print_range(const_cast<Node*>(root->right), l, r);
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ nullptr, nullptr, 2 });
    Node node2({ nullptr, &node1, 1 });
    Node node3({ nullptr, nullptr, 8 });
    Node node4({ nullptr, &node3, 8 });
    Node node5({ &node4, nullptr, 9 });
    Node node6({ &node5, nullptr, 10 });
    Node node7({ &node2, &node6, 5 });
    print_range(&node7, 2, 8);
}

int main() {
    test();
}
#endif