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

int countNodes(Node* root) {
    if (root == NULL) {
        return 0; 
    }


    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);


    int totalNodes = countNodes(root);


    printf("The total number of nodes in the binary tree is %d.\n", totalNodes);



    return 0;
}