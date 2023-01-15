#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string& value, Node* next) : value(value), next(next) {}
};
#endif


Node* solution(Node* head, int idx) {
    if (idx == 0) {
        head = head->next;
        return head;
    }
    
    Node* node = head;
    int i = 1;

    while (i < idx) {
        node = node->next;
        ++i;
    }

    node->next = node->next->next;
    return head;
}

#ifndef REMOTE_JUDGE
void test() {
    
    {
        Node node3("node3", nullptr);
        Node node2("node2", &node3);
        Node node1("node1", &node2);
        Node node0("node0", &node1);

        Node* new_head = solution(&node0, 0);
        assert(new_head == &node1);
        assert(new_head->next == &node2);
        assert(new_head->next->next == &node3);
        assert(new_head->next->next->next == nullptr);
    }
    {
        Node node3("node3", nullptr);
        Node node2("node2", &node3);
        Node node1("node1", &node2);
        Node node0("node0", &node1);

        Node* new_head = solution(&node0, 2);
        assert(new_head == &node0);
        assert(new_head->next == &node1);
        assert(new_head->next->next == &node3);
        assert(new_head->next->next->next == nullptr);
    }
}

int main() {
    test();
}
#endif