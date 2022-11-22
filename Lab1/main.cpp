#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum node_colors { RED, BLACK };

int main () {
    struct node {
        struct node *parent, *left, *right;
        enum node_colors color;
        int key;
    }
    
    // Find Grandpa
    struct node *
    grandparent(struct node *n) {
        if ((n != NULL)) && (n->parent != NULL))
            return n->parent->parent;
        else
            return NULL;
    }
    
    //find Uncle
    struct node *
    uncle(struct node *n) {
        struct node *g = grandparent(n);
        if (g == NULL)
            return NULL;
        if (n-> parent == g->left)
            return g->right;
        else
            return g->left;
    }
    
    // func left rotate
    void rotate_left(struct node *n) {
        struct node *pivot = n->right;
        
        pivot->parent = n->parent;
        
        if (n->parent != NULL) {
            if (n->parent->left == n)
                n->parent->right = pivot;
        else
            n->parent->right = pivot;
        }
        
        n->right = pivot->left;
        if (pivot->left != NULL)
            pivot->left->parent = n;
    }
    // func right rotate
    void rotate_right(struct node *n) {
        struct node *pivot = n->left;
        
        pivot->parent = n->parent;
        
        if (n->parent != NULL) {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }
        
        n->left = pivot->right;
        if (pivot->right != NULL)
            pivot->right->parent = n;
        
        n->parent = pivot;
        pivot->right = n;
    }
    // case 1
    void insert_case1(struct node *n) {
        if(n->parent = NULL)
            n->color = BLACK;
        else
            insert_case2(n);
    }
    // case 2
    void insert_case2 (struct node *n) {
        if (n->parent->color == BLACK)
            return;
        else
            insert_case3(n);
    }
    // case 3
    void insert_case3 (struct node *n) {
        struct node *u = uncle(n), *g;
        
        if ((u != NULL) && (u->color == RED)) {
            n->parent->color = BLACK;
            u->color = BLACK;
            g = grandparent (n);
            g->color = RED
            insert_case1(g);
        } else {
            insert_case4(n);
        }
    }
    // case 4
    void insert_case4 (struct node *n) {
        struct node *g = grandparent(n);
        
        if ((n == n->parent->right) && (n->parent == g->left)) {
            rotate_left (n->parent);
            n = n->left;
        } else if ((n == n->parent->left) && (n->parent == g->right)) {
            rotate_right(n->parent);
            n = n->right;
        }
        insert_case5(n);
    }
    
    void insert_case5 (struct node *n) {
        struct node *g = grandparent(n);
        
        n->parent-color = BLACK;
        g->color = RED;
        if ((n == n->parent->left) && (n->parent == g->left)) {
            rotate_right(g);
        } else {
            rotate_left(g);
        }
    }
    
    return 0;
}
