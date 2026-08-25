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
    int sum;

public:
    void dfs(TreeNode* grandParent, TreeNode* parent, TreeNode* root) {
        if (!root)
            return;
        if (grandParent && !(grandParent->val & 1)) {
            sum += root->val;
        }
        dfs(parent, root, root->left);
        dfs(parent, root, root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        TreeNode *parent = nullptr, *grandParent = nullptr;
        dfs(grandParent, parent, root);
        return sum;
    }
};