#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

// binary search tree data structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

typedef node *tree;

// binary search tree ADT methods
void init(tree *t);
void insert(tree *t, int d);
void removeNode(tree *t, int d);
node *search(tree t, int d);

void inorder_traverse(tree t);
void preorder_traverse(tree t);
void postorder_traverse(tree t);

#endif // TREE_H_INCLUDED
