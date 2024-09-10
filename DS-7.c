#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 


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


int findMin(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX; 
    }

    int minValue = root->value;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    if (leftMin < minValue) {
        minValue = leftMin;
    }

    if (rightMin < minValue) {
        minValue = rightMin;
    }

    return minValue;
}


int findMax(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN; 
    }

    int maxValue = root->value;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > maxValue) {
        maxValue = leftMax;
    }

    if (rightMax > maxValue) {
        maxValue = rightMax;
    }

    return maxValue;
}


int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);


    int minValue = findMin(root);
    int maxValue = findMax(root);

    printf("Minimum value in the binary tree: %d\n", minValue);
    printf("Maximum value in the binary tree: %d\n", maxValue);


    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}