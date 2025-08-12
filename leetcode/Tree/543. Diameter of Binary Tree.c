/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root, int *diameter) {
    
    if(root == NULL) return 0 ;


    int rightDepth = maxDepth(root->right,diameter);
    int leftDepth = maxDepth(root->left,diameter);

    int pathLength = leftDepth + rightDepth;
    if (pathLength > *diameter) {
        *diameter = pathLength;
    }

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;

}


int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    maxDepth(root, &diameter);
    return diameter;
}
