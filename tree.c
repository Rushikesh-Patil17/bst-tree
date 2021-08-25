#include <stdio.h>
#include "tree.h"
#include <stdlib.h>


// initialize the BST
void init(tree *t) {
    *t = NULL;
    return;
}

void insert(tree *t, int d) {
    // create node
    node *nn = (node *)malloc(sizeof(node));
    nn->data = d;
    nn->left = nn->right = NULL;

    // check if node is created or not
    if(!nn)
        return;

    // if tree is empty, make new node the root
    if(!*t) {
        *t = nn;
        return;
    }

    // get the parent where we will add the child node
    else {
        node *parentptr = NULL;
        node *ptr = *t;

        while(ptr) {
            parentptr = ptr;

            // if value is less navigate to left
            if(d < ptr->data)
                ptr = ptr->left;
            // else if value is greater navigate to right
            else if(d > ptr->data)
                ptr = ptr->right;
            // violence of BST criteria, return
            else
                return;
        }

        // add according to the value
        if(d < parentptr->data)
            parentptr->left = nn;
        else
            parentptr->right = nn;
        return;
    }
}

void removeNode(tree *t, int d) {
    // if tree is empty, return NULL
    if(!*t)
        return;

    node *ptr = *t;
    node *parentptr = NULL;

    // try to find the node
    while(ptr) {
        // found the element
        if(d == ptr->data)
            break;

        parentptr = ptr;
        // if value is less navigate to left
        if(d < ptr->data)
            ptr = ptr->left;
        // else if value is greater navigate to right
        else
            ptr = ptr->right;
    }

    // if p is NULL then data not found
    if(!ptr)
        return;

    // check for leaf node
    else if(ptr->left == NULL && ptr->right == NULL) {
        delete_leaf(t, ptr, parentptr);
    }

    // node with only one child
    else if((ptr->left && !ptr->right) || (!ptr->left && ptr->right)) {
        delete_with_one_child(t, ptr, parentptr);
    }

    // node with two child
    /*
        Procedure:
        1. Find the minimum element in right subtree.
        2. Copy the value to the target node.
        3. Delete duplicate from right subtree.

        OR

        1. Find the maximum element in left subtree.
        2. Copy the value to the target node.
        3. Delete duplicate from left subtree.
    */

    else {
        node *q = ptr;
        node *p = ptr->right;

        while(p->left) {
            q = p;
            p = p->left;
        }

        ptr->data = p->data;

        if(p->left == NULL && p->right == NULL)
            delete_leaf(t, p, q);
        else
            delete_with_one_child(t, p, q);
        return;
    }

    return;
}

void delete_leaf(tree *t, node *p, node *parent) {
    // check if there is only one node in the tree
    if(!parent) {
        *t = NULL;
        free(p);
        return;
    }

    // delete non-root node
    if(parent->left == p)
        parent->left = NULL;
    else
        parent->right = NULL;
}

void delete_with_one_child(tree *t, node *ptr, node *parent) {
    // check if node is root
    if(!parent) {
        if(ptr->left)
            *t = ptr->left;
        else
            *t = ptr->right;
    }

    else {
        // ptr is at left of parentptr
        if(parent->left == ptr) {
            if(ptr->left)
                parent->left = ptr->left;

            else
                parent->left = ptr->right;
        }

        // ptr is at right of parentptr
        else {
            if(ptr->left)
                parent->right = ptr->left;

            else
                parent->right = ptr->right;
        }
    }

    free(ptr);
    return;
}

node *find_inorder_suc(tree t) {
    // start searching in the right subtree
    node *p = t->right;

    while(p->left)
        p = p->left;

    return p;
}

// inorder traversal of BST
void inorder_traverse(tree t) {
    if(!t)
        return;

    inorder_traverse(t->left);
    printf("%d\n", t->data);
    inorder_traverse(t->right);
}

// preorder traversal of BST
void preorder_traverse(tree t) {
    if(!t)
        return;

    printf("%d\n", t->data);
    preorder_traverse(t->left);
    preorder_traverse(t->right);
}

// postorder traversal of BST
void postorder_traverse(tree t) {
    if(!t)
        return;

    postorder_traverse(t->left);
    postorder_traverse(t->right);
    printf("%d\n", t->data);
}

node *search(tree t, int d) {
    // if tree is empty, return NULL
    if(!t)
        return NULL;

    // try to find the node
    else {
        node *ptr = t;

        while(ptr) {
            // if value is less navigate to left
            if(d < ptr->data)
                ptr = ptr->left;
            // else if value is greater navigate to right
            else if(d > ptr->data)
                ptr = ptr->right;
            // found the element return
            else if(d == ptr->data)
                return ptr;
        }
    }

    return NULL;
}
