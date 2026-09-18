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
    TreeNode* dummy = new TreeNode(-1);

public:
    void buildTree(TreeNode* root, TreeNode*& curr) {
        if (!root)
            return;
        buildTree(root->left, curr);
        root->left = nullptr;
        curr->right = root;
        curr = root;
        buildTree(root->right, curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* curr = dummy;
        buildTree(root, curr);
        return dummy->right;
    }
};