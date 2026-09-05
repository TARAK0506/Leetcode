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
    pair<int, bool> isPerfectSubTree(TreeNode* root) {
        if (!root)
            return {0, true};
        auto leftCheck = isPerfectSubTree(root->left);
        auto rightCheck = isPerfectSubTree(root->right);
        int height = 1 + max(leftCheck.first, rightCheck.first);

        bool isPerfect = (leftCheck.first == rightCheck.first &&
                          leftCheck.second && rightCheck.second);

        if (isPerfect) {
            int nodes = (1 << height) - 1;
            ans.emplace_back(nodes);
            return {height, isPerfect};
        }
        return {height, isPerfect};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        isPerfectSubTree(root);
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans.size() >= k ? ans[k - 1] : -1;
    }
};