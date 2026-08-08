/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = nullptr;
    TreeNode* dfs(TreeNode* cloned, TreeNode* target) {
        if (!cloned)
            return ans;
        if (cloned->val == target->val)
            ans = cloned;
        dfs(cloned->left, target);
        dfs(cloned->right, target);
        return ans;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (!cloned)
            return nullptr;
        return dfs(cloned, target);
    }
};