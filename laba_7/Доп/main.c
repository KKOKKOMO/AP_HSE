#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;


int currentIndex = 0; 


TreeNode* createNode(int value, TreeNode* parent) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

TreeNode* buildTree(int* values, int N, int currentLevel, int maxLevel, TreeNode* parent) {
    if (currentLevel > maxLevel || currentIndex >= N) {
        return NULL;
    }

    // Create current node
    TreeNode* node = createNode(values[currentIndex++], parent);

    // Build left and right subtrees
    node->left = buildTree(values, N, currentLevel + 1, maxLevel, node);
    node->right = buildTree(values, N, currentLevel + 1, maxLevel, node);

    return node;
}

void printTree(TreeNode* root, int level) {
    if (!root) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%d\n", root->value);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int L = 3; 
    int N = 10;
    int values[] = {10, 5, 2, 8, 7, 15, 12, 20, 25, 30};

    if (N <= L) {
        printf("Error: N must be greater than L\n");
        return 1;
    }

    TreeNode* root = buildTree(values, N, 1, L, NULL);

    printf("Constructed tree (prefix order):\n");
    printTree(root, 0);

    printf("Pointer to the root node: %p\n", (void*)root);

    freeTree(root);

    return 0;
}

