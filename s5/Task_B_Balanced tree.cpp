﻿#ifndef REMOTE_JUDGE
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
#include <cmath>
#include <stack>

using namespace std;


bool Solution(const Node* root) {
    struct S {
        const Node* first;
        const Node* second;
        int l_depth = 0;
        int r_depth = 0;
        bool is_left;
        int value;
    };

    std::stack<S> st;

    st.push({ root->left, root->right, 0, 0, true, root->value });

    while (st.size() > 0) {
        if (!st.top().first && !st.top().second) {
            if (std::abs(st.top().l_depth - st.top().r_depth) > 1) {
                return false;
            }
            else {
                int l_depth = st.top().l_depth;
                int r_depth = st.top().r_depth;
                bool is_left = st.top().is_left;
                st.pop();
                
                if (st.size() > 0) {
                    if (is_left) {
                        st.top().l_depth = std::max(l_depth + 1, r_depth + 1);
                    }
                    else {
                        st.top().r_depth = std::max(l_depth + 1, r_depth + 1);
                    }
                }
                
            }
        }
        else if (st.top().first) {
            S temp = st.top();
            st.top().first = nullptr;
            st.push({ temp.first->left, temp.first->right, 0, 0, true, temp.first->value });
        }
        else if (st.top().second) {
            S temp = st.top();
            st.top().second = nullptr;
            st.push({ temp.second->left, temp.second->right, 0, 0, false, temp.second->value });
        }
    }
    return true;
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ -5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 10, nullptr, nullptr });
        Node node5({ 2, &node3, &node4 });
        assert(Solution(&node5));
    }

    {
        Node node1({ 2, nullptr, nullptr });
        Node node2({ 0, nullptr, nullptr });
        Node node3({ 1, &node1, &node2 });
        assert(Solution(&node3));
    }

    {
        Node node1({ 3, nullptr, nullptr });
        Node node2({ 6, nullptr, nullptr });
        Node node3({ 0, &node1, &node2 });
        Node node4({ 2, nullptr, nullptr });
        Node node5({ 1, &node4, &node3 });
        assert(Solution(&node5));
    }

    {
        Node node1({ 2, nullptr, nullptr });
        Node node2({ 12, nullptr, nullptr });
        Node node3({ 4, &node2, nullptr });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 7, &node3, &node4 });
        Node node6({ 0, &node1, &node5 });
        assert(!Solution(&node6));
    }
}

int main() {
    test();
}
#endif