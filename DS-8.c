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


int calculateHeight(TreeNode* root) {
    if (root == NULL) {
       return -1;  
    }


    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);


    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);


    int height = calculateHeight(root);
    printf("Height of the binary tree: %d\n", height);


    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}