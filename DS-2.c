
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


TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        
        return createNode(value);
    }
    
    if (value < root->value) {
       
        root->left = insertNode(root->left, value);
    } else {
        
        root->right = insertNode(root->right, value);
    }
    
    return root;
}


void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}


int main() {
    TreeNode* root = NULL;

   
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

   
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    
    return 0;
}
