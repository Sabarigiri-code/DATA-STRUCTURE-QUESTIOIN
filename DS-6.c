#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


bool searchTree(TreeNode* root, int value) {
    if (root == NULL) {

        return false;
    }

    if (root->value == value) {
        return true;
    }


    return searchTree(root->left, value) || searchTree(root->right, value);
}


int main() {

    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int searchValue = 5;


    if (searchTree(root, searchValue)) {
        printf("Value %d found in the binary tree.\n", searchValue);
    } else {
        printf("Value %d not found in the binary tree.\n", searchValue);
    }


    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}