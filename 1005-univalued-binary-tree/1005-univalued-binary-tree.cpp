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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*>q;
        int val = root->val;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++){
              TreeNode* curr = q.front();
              q.pop();
              if (curr->left) q.push(curr->left);
              if (curr->right) q.push(curr->right);
              if (curr->val != val) return false;
            }
        }
        return true;
    }
};