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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        int currlevel = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelnodes;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                levelnodes.emplace_back(curr);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (currlevel % 2 == 1) {
                int left = 0, right = levelnodes.size() - 1;
                while (left < right) {
                    swap(levelnodes[left]->val, levelnodes[right]->val);
                    left++;
                    right--;
                }
            }
            currlevel++;
        }
        return root;
    }
};