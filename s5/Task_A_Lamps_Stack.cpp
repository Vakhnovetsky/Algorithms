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
#include <utility>

using namespace std;


int Solution(const Node* root) {
    std::stack<std::pair<Node*, Node*>> st;
    int res = root->value;

    st.push({ const_cast<Node*>(root->left), const_cast<Node*>(root->right) });

    while (st.size() > 0) {
        if (st.top().first == nullptr && st.top().second == nullptr) {
            st.pop();
        }
        else if (st.top().first != nullptr) {
            auto temp = st.top().first;
            st.top().first = nullptr;
            st.push({ const_cast<Node*>(temp->left), const_cast<Node*>(temp->right) });
            res = std::max(res, temp->value);
        }
        else if (st.top().second != nullptr) {
            auto temp = st.top().second;
            st.top().second = nullptr;
            st.push({ const_cast<Node*>(temp->left), const_cast<Node*>(temp->right) });
            res = std::max(res, temp->value);
        }
    }

    return res;
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        assert(Solution(&node1) == 1);
    }

    
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ -5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 2, &node3, nullptr });
        assert(Solution(&node4) == 3);
    }
    
}

int main() {
    test();
}
#endif