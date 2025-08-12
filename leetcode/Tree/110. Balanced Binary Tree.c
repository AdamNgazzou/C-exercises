#include <stdbool.h>
#include <stdlib.h>

int height(struct TreeNode* root) {
    if (root == NULL) return 0;

    int leftDepth = height(root->left);
    int rightDepth = height(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    // Recursively check left and right subtrees are balanced
    return isBalanced(root->left) && isBalanced(root->right);
}