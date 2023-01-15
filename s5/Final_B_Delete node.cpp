/*
Задача. B. Удали узел
Описание. 
Реализация поиска и удаления узла в бинарном дереве поиска

ВРЕМЕННАЯ СЛОЖНОСТЬ
Временная сложность зависит от высоты дерева. 
Поиск удаляемого узла и нахождение узла, которое вставляется на замену осуществляется за один проход по дереву по высоте от корня до листа в худшем случае.
Таким образом сложность в худшем случае O(h), где h - высота дерева.

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Проход по дереву осуществляется через цикл. Перед циклом выделяется дополнительная память под хранение указателя на текущий узел и его родителя. 
Выделение данной памяти константно и не зависит от размера дерева О(1).
*/

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
#include <cassert>

Node* remove(Node* root, int key) {
    if (root) {
        Node* node = root;
        Node* parent = nullptr;

        while (true) {
            if (key == node->value) {
                Node* new_node;
                if (node->left) {
                    new_node = const_cast<Node*>(node->left);
                    Node* p = nullptr;

                    while (new_node->right != nullptr) {
                        p = new_node;
                        new_node = const_cast<Node*>(new_node->right);
                    }

                    if (p) {
                        p->right = nullptr;
                        new_node->left = node->left;
                    }

                    new_node->right = node->right;
                }
                else {
                    new_node = const_cast<Node*>(node->right);
                }

                if (parent) {
                    if (parent->left == node) {
                        parent->left = new_node;
                    }
                    else {
                        parent->right = new_node;
                    }
                    break;
                }
                else {
                    root = new_node;
                    break;
                }
            }
            else {
                parent = node;
                if (node->left && node->value > key) {
                    node = const_cast<Node*>(node->left);
                }
                else if (node->right && node->value < key) {
                    node = const_cast<Node*>(node->right);
                }
                else {
                    break;
                }
            }
        }  
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
	Node node1({ nullptr, nullptr, 2 });
	Node node2({ &node1, nullptr, 3 });
	Node node3({ nullptr, &node2, 1 });
	Node node4({ nullptr, nullptr, 6 });
	Node node5({ &node4, nullptr, 8 });
	Node node6({ &node5, nullptr, 10 });
	Node node7({ &node3, &node6, 5 });
	Node* newHead = remove(&node7, 10);
	assert(newHead->value == 5);
	assert(newHead->right == &node5);
	assert(newHead->right->value == 8);
}

int main() {
    test();
}
#endif