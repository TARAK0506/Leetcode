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
    bool isLeaf(TreeNode* root) { 
        return !root->left && !root->right; 
    }
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int>& temp,
             int target) {
        if (!root)
            return;
        temp.emplace_back(root->val);
        int currsum = target - root->val;
        if (currsum == 0 && isLeaf(root)) {
            ans.emplace_back(temp);
        }
        dfs(root->left, ans, temp, currsum);
        dfs(root->right, ans, temp, currsum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, ans, temp, targetSum);
        return ans;
    }
};