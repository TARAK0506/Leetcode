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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                k--;
                if (k == 0)
                    ans = curr->val;
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
                    k--;
                    if (k == 0)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};