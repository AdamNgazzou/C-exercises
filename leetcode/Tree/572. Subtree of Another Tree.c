bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) return false;

    // If current node matches, return true
    if (isSameTree(root, subRoot)) return true;

    // Otherwise, check left or right subtree
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
