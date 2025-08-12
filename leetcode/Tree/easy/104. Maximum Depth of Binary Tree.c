/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    
    if(root == NULL) return 0 ;


    int rightDepth = maxDepth(root->right);
    int leftDepth = maxDepth(root->left);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;

}