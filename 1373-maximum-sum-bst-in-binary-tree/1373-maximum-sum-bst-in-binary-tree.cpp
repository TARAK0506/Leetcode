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
struct Node {
    int minVal, maxVal, sum;

public:
    Node(int min, int max, int sum = 0) : minVal(min), maxVal(max), sum(sum) {}
};
class Solution {
    int maxSum;

public:
    Node solve(TreeNode* root) {
        if (!root)
            return Node(INT_MAX, INT_MIN, 0);
        auto leftSubTree = solve(root->left);
        auto rightSubTree = solve(root->right);
        if (leftSubTree.maxVal < root->val && root->val < rightSubTree.minVal) {
            int currSum = root->val + leftSubTree.sum + rightSubTree.sum;
            maxSum = max(maxSum, currSum);
            int currMin = min(root->val, leftSubTree.minVal);
            int currMax = max(root->val, rightSubTree.maxVal);
            return Node(currMin, currMax, currSum);
        }
        return Node(INT_MIN, INT_MAX, max(leftSubTree.sum, rightSubTree.sum));
    }
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        solve(root);
        return maxSum;
    }
};