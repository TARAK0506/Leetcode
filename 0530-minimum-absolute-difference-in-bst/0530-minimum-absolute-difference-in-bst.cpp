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
    int minDiff;
    TreeNode* prev;

public:
    void inOrder(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (!root)
            return;
        inOrder(root->left, prev, minDiff);
        if (prev) {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }
        prev = root;
        inOrder(root->right, prev, minDiff);
    }
    int getMinimumDifference(TreeNode* root) {
        prev = nullptr;
        minDiff = INT_MAX;
        inOrder(root, prev, minDiff);
        return minDiff;
    }
};