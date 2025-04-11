/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, int curr, int targetsum) {
        if (!root)
            return false;
        curr = curr + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return curr == targetsum;
        return dfs(root->left, curr, targetsum) ||
               dfs(root->right, curr, targetsum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};