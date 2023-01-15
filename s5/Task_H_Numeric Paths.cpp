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

#include <cmath>
#include <iostream>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

int Solution(const Node* root) {
    if (!root->left && !root->right) {
        return root->value;
    }
    
    struct st {
        Node* l;
        Node* r;
        std::string number;
    };

    std::stack <st> tree;
    tree.push({ const_cast<Node*>(root->left), const_cast<Node*>(root->right), to_string(root->value) });
    int sum = 0;

    while (!tree.empty()) {
        if (!tree.top().l && !tree.top().r) {
            tree.pop();
        }
        else {
            if (tree.top().l) {
                auto temp = tree.top();
                tree.top().l = nullptr;
                tree.push({ const_cast<Node*>(temp.l->left), const_cast<Node*>(temp.l->right), temp.number + std::to_string(temp.l->value) });

                if (!tree.top().l && !tree.top().r) {
                    sum += std::stoi(tree.top().number);
                }
            }
            else if (tree.top().r) {
                auto temp = tree.top();
                tree.top().r = nullptr;
                tree.push({ const_cast<Node*>(temp.r->left), const_cast<Node*>(temp.r->right), temp.number + std::to_string(temp.r->value) });

                if (!tree.top().l && !tree.top().r) {
                    sum += std::stoi(tree.top().number);
                }
            }
        }
    }

    return sum;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 2, nullptr, nullptr });
    Node node2({ 1, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 2, nullptr, nullptr });
    Node node5({ 1, &node4, &node3 });
    assert(Solution(&node5) == 275);
}

int main() {
    test();
}
#endif