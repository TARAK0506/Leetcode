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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr = root;
        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            if (node != root) {
                curr->right = node;
                curr->left = nullptr;
            }
            curr = node;
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
    }
};