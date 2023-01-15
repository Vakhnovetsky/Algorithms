#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>
#include <vector>

struct Node {
    Node(const std::string& value, Node* next, Node* prev)
        : value(value)
        , next(next)
        , prev(prev)
    {}
    std::string value;
    Node* next;
    Node* prev;
};
#endif

Node* solution(Node* head) {
    std::vector<Node*> vec;
    while (head->next != nullptr) {
        vec.push_back(head);
        head = head->next;
    }
    vec.push_back(head);

    for (Node* v : vec) {
        Node* temp = v->next;
        v->next = v->prev;
        v->prev = temp;
    }

    return head;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr, nullptr);
    Node node2("node2", nullptr, nullptr);
    Node node1("node1", nullptr, nullptr);
    Node node0("node0", nullptr, nullptr);
    node0.next = &node1;

    node1.next = &node2;
    node1.prev = &node0;

    node2.next = &node3;
    node2.prev = &node1;

    node3.prev = &node2;
    Node* new_head = solution(&node0);
    assert(new_head == &node3);
    assert(node3.next == &node2);
    assert(node2.next == &node1);
    assert(node2.prev == &node3);
    assert(node1.next == &node0);
    assert(node1.prev == &node2);
    assert(node0.prev == &node1);
}

int main() {
    test();
}
#endif