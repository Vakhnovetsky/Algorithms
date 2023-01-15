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
#include <optional>
#include <stack>

using namespace std;

bool Solution(const Node* root) {
    
    struct S {
        const Node* first;
        const Node* second;
        std::optional<int> min_l;
        std::optional<int> max_l;
        std::optional<int> min_r;
        std::optional<int> max_r;
    };

    std::stack<S> st;

    st.push({ root->left, root->right, {}, root->value, root->value, {} });

    while (st.size() > 0) {
        if (!st.top().first && !st.top().second) {
            st.pop();
        }
        else if (st.top().first) {
            if (st.top().max_l.has_value() && st.top().max_l.value() <= st.top().first->value ||
                st.top().min_l.has_value() && st.top().min_l.value() >= st.top().first->value) {
                return false;
            }

            S temp = st.top();
            st.top().first = nullptr;

            st.push({ temp.first->left, temp.first->right, temp.min_l, temp.first->value, temp.first->value, temp.min_r });
        }
        else if (st.top().second) {
            if (st.top().min_r.has_value() && st.top().min_r.value() >= st.top().second->value ||
                st.top().max_r.has_value() && st.top().max_r.value() <= st.top().second->value) {
                return false;
            }

            auto temp = st.top();
            st.top().second = nullptr;

            st.push({ temp.second->left, temp.second->right, temp.max_l, temp.second->value, temp.second->value, temp.max_r });
        }
    }

    return true;
}


#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 4, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(Solution(&node5));
    }
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(!Solution(&node5));
    }
}


int main() {
    test();
}
#endif