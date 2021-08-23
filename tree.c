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
