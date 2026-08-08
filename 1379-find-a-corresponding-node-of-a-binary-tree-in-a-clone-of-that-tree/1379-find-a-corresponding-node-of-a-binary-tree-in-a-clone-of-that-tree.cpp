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
    void dfs(TreeNode* cloned, TreeNode* target, TreeNode*& ptr) {
        if (!cloned)
            return;
        if (cloned->val == target->val) {
            ptr = cloned;
            return;
        }
        dfs(cloned->left, target, ptr);
        dfs(cloned->right, target, ptr);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        TreeNode* ptr = nullptr;
        if (!cloned)
            return ptr;
        dfs(cloned, target, ptr);
        return ptr;
    }
};