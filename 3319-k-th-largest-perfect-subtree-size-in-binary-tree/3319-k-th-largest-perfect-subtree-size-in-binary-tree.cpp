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
    vector<long long> ans;

public:
    long long findHeight(TreeNode* root) {
        if (!root)
            return 0;
        long long leftHeight = findHeight(root->left);
        long long rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    bool isPerfectSubTree(TreeNode* root) {
        if (!root)
            return true;

        long long left = findHeight(root->left);
        long long right = findHeight(root->right);

        bool leftSubTree = isPerfectSubTree(root->left);
        bool rightSubTree = isPerfectSubTree(root->right);

        if (left == right && leftSubTree && rightSubTree) {
            long long height = findHeight(root);
            long long nodes = (1 << height) - 1;
            ans.push_back(nodes);
            return true;
        }
        return false;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        isPerfectSubTree(root);
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans.size() >= k ? ans[k - 1] : -1;
    }
};