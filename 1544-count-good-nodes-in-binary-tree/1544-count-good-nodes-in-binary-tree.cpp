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
    int count = 0;
    void dfs(TreeNode* node, int CurrMax) {
        if (!node)
            return;
        if (node->val >= CurrMax) {
            count++;
            CurrMax = node->val;
        }
        dfs(node->left, CurrMax);
        dfs(node->right, CurrMax);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};