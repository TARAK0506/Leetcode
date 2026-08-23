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
    int n;
    vector<int> nodes;

public:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        nodes.emplace_back(root->val);
        inOrder(root->right);
    }
    TreeNode* buildTree(int left, int right, vector<int>& nodes) {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildTree(left, mid - 1, nodes);
        root->right = buildTree(mid + 1, right, nodes);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        n = nodes.size();
        return buildTree(0, n - 1, nodes);
    }
};