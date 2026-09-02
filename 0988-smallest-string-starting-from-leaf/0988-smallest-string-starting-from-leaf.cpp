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
    string ans = "";
    bool isLeaf(TreeNode* node) { 
        return node && !node->left && !node->right; 
    }

public:
    void backtrack(TreeNode* root, string s) {
        if (!root)
            return;
        s += char('a' + root->val);
        if (isLeaf(root)) {
            string curr = s;
            reverse(curr.begin(), curr.end());
            if (ans.empty() || curr < ans) {
                ans = curr;
            }
            s.pop_back();
            return ;
        }
        backtrack(root->left, s);
        backtrack(root->right, s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        backtrack(root, "");
        return ans;
    }
};