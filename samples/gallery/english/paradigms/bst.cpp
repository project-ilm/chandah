// a binary search tree class, in C++
#include <iostream>
class Tree {
  struct Node { int key; Node *left = nullptr, *right = nullptr; };
  Node *root = nullptr;
  Node *insert(Node *node, int key) { if (!node) { node = new Node; node->key = key; return node; } if (key < node->key) node->left = insert(node->left, key); else node->right = insert(node->right, key); return node; }
  void inorder(Node *node) { if (!node) return; inorder(node->left); std::cout << node->key << " "; inorder(node->right); }
public:
  void insert(int key) { root = insert(root, key); }
  void print() { inorder(root); std::cout << std::endl; }
};
int main() { Tree tree; int keys[] = {5, 3, 8, 1, 4}; for (int key : keys) tree.insert(key); tree.print(); return 0; }
