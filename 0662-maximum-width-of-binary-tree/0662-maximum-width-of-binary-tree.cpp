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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            long long size = q.size();
            long long minVal = q.front().second;
            long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long id = q.front().second - minVal;
                q.pop();

                if (i == 0)
                    first = id;
                if (i == size - 1)
                    last = id;
                if (curr->left) 
                    q.push({curr->left, 2 * id + 1});
                
                if (curr->right) 
                    q.push({curr->right, 2 * id + 2});
                
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};