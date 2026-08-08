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
    bool isLeaf(TreeNode* node) { 
        return node && !node->left && !node->right; 
    }
    int dfs(TreeNode* root) {
        if (isLeaf(root))
            return root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int value = root->val;
        return value == 2 ? l || r : l && r;
    }
    bool evaluateTree(TreeNode* root) { 
        return dfs(root); 
    }
};