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
    int maxLevelSum(TreeNode* root) {
        int level = 1, ans = 1, maxsum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        if (!root)
            return 0;
        while (!q.empty()) {
            int size = q.size();
            int level_sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level_sum += curr->val;
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            if (maxsum < level_sum) {
                maxsum = level_sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};