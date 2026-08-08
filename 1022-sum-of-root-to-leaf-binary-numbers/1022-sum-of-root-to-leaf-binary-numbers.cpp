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
    int sum = 0;

public:
    bool isLeaf(TreeNode* node) { 
        return node && !node->left && !node->right; 
    }
    int dfs(TreeNode* root, int sum) {
        if (!root)
            return 0;
        sum = sum * 2 + root->val;
        if (isLeaf(root))
            return sum;
        int l = dfs(root->left, sum);
        int r = dfs(root->right, sum);
        return l + r;
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, sum); 
    }
};