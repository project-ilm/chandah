#include <stdio.h>
#include <stdlib.h>
/* binary search tree: insert and in-order traversal */
struct node { int key; struct node *left, *right; };
struct node *insert(struct node *root, int key) {
  if (!root) { root = calloc(1, sizeof *root); root->key = key; return root; }
  if (key < root->key) root->left = insert(root->left, key); else root->right = insert(root->right, key);
  return root;
}
void inorder(struct node *root) { if (!root) return; inorder(root->left); printf("%d ", root->key); inorder(root->right); }
int height(struct node *root) { if (!root) return 0; int left = height(root->left), right = height(root->right); return 1 + (left > right ? left : right); }
int main(void) {
  int keys[] = {50, 30, 70, 20, 40, 60, 80, 35};
  struct node *root = NULL;
  for (int index = 0; index < 8; index++) root = insert(root, keys[index]);
  inorder(root);
  printf("\nheight %d\n", height(root));
  return 0;
}
