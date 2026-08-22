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
    TreeNode* rightMostNode(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        if (root->val == key) {
            if (!root->left && !root->right)
                return nullptr;
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;
            TreeNode* rightSubTree = root->right;
            TreeNode* leftSubTree = root->left;
            TreeNode* link = rightMostNode(leftSubTree);
            link->right = rightSubTree;
            return leftSubTree;
        }
        return root;
    }
};