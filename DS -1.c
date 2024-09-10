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


void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}


int main() {

    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);


    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");


    free(root->left);
    free(root->right);
    free(root);

    return 0;
}