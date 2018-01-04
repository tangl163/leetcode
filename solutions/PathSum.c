/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool
hasPathSum(struct TreeNode *root, int sum)
{
    if (!root)
        return 0;
    else if (root->val == sum && !root->left && !root->right)
        return 1;
    else
        return hasPathSum(root->left, sum - root->val)
            || hasPathSum(root->right, sum - root->val);
}

