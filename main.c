#include <stdio.h>
#include "tree.h"

int main() {
    tree t;
    init(&t);
    
    insert(&t, 12);
    insert(&t, 28);
    insert(&t, 38);
    insert(&t, 48);
    insert(&t, 1);
    insert(&t, 8);
    insert(&t, 15);
    insert(&t, 45);
    insert(&t, 50);
    
    inorder_traverse(t);
    
    removeNode(&t, 8);
    removeNode(&t, 45);
    
    preorder_traverse(t);
    postorder_traverse(t);
    
    return 0;
}
