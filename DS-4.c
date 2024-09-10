#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int value;              
    struct TreeNode* left;  
    struct TreeNode* right;
} TreeNode;


TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);     
        preorderTraversal(root->left);   
        preorderTraversal(root->right); 
    }
}


int main() {

    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);


    printf("Pre-order traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");


    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}