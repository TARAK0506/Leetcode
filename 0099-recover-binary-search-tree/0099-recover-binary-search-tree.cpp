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
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode* prev = nullptr;

public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val > curr->val) {
                    if (!first)
                        first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (!first)
                            first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        if (first && second)
            swap(first->val, second->val);
    }
};