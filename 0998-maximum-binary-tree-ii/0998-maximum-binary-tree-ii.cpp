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
    pair<int, int> findMax(int left, int right, vector<int>& nodes) {
        int maxVal = -1, maxIdx = -1;
        for (int i = left; i <= right; i++) {
            if (nodes[i] > maxVal) {
                maxVal = nodes[i];
                maxIdx = i;
            }
        }
        return {maxVal, maxIdx};
    }
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
        auto maximum = findMax(left, right, nodes);
        int val = maximum.first;
        int idx = maximum.second;
        TreeNode* root = new TreeNode(val);
        root->left = buildTree(left, idx - 1, nodes);
        root->right = buildTree(idx + 1, right, nodes);
        return root;
    }

public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inOrder(root);
        nodes.emplace_back(val);
        n = nodes.size();
        return buildTree(0, n - 1, nodes);
    }
};