#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int findDepth(Node* root, int target, int depth) {

    if (root == NULL) {
        return -1; 
    }


    if (root->data == target) {
        return depth;
    }


    int leftDepth = findDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }

    return findDepth(root->right, target, depth + 1);
}


int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int target = 5;
    int depth = findDepth(root, target, 0);

    if (depth != -1) {
        printf("The depth of node with data %d is %d.\n", target, depth);
    } else {
        printf("Node with data %d not found in the tree.\n", target);
    }


    return 0;
}