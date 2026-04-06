#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

#define FL(i,a,b) for(int i = a ; i < b ; i++)
typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always RED
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// --- Tree Rotations ---
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;
    x->right = y;
    y->parent = x;
}

// --- Fixing Red-Black Violations ---
void insertFixup(Node** root, Node* z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // Uncle
            if (y != NULL && y->color == RED) { // Case 1: Uncle is RED
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else { 
                if (z == z->parent->right) { // Case 2: Uncle is BLACK, Triangle shape
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Case 3: Uncle is BLACK, Line shape
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            // Symmetric code for when parent is a right child
            Node* y = z->parent->parent->left; // Uncle
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK; // Root is always BLACK
}

// --- Standard BST Insert with Fixup ---
void insertNode(Node** root, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = *root;

    // Standard BST traversal to find insertion point
    while (x != NULL) {
        y = x;
        if (z->data < x->data) x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if (y == NULL) *root = z;
    else if (z->data < y->data) y->left = z;
    else y->right = z;

    // Fix Red-Black Tree violations
    insertFixup(root, z);
}

// --- Calculating Black Height ---
int getBlackHeight(Node* root) {
    int blackCount = 0;
    Node* curr = root;
    
    // Because all paths have the same number of black nodes, 
    // we can safely just walk straight down the left spine.
    while (curr != NULL) {
        if (curr->color == BLACK) {
            blackCount++;
        }
        curr = curr->left;
    }
    
    // Note: Some formal definitions count the NULL leaf itself as a black node.
    // If your specific platform's test cases expect +1 higher than this output, 
    // simply change this to: return blackCount + 1;
    return blackCount; 
}

int main() {
    int n;
    scanf("%d",&n);

    Node* root = NULL;
    int tmp;

    FL(i,0,n){
        scanf("%d", &tmp);
        insertNode(&root, tmp);
    }

    printf("%d\n", getBlackHeight(root));
    return 0;
}