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
    void solve(TreeNode* root, int& res, int maxVal, int minVal) {
        if (!root)
            return;
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        res = max(res, maxVal - minVal);
        solve(root->left, res, maxVal, minVal);
        solve(root->right, res, maxVal, minVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0, maxVal = INT_MIN, minVal = INT_MAX;
        solve(root, res, maxVal, minVal);
        return res;
    }
};