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
    long long sum, maxProd;
    const long long MOD = 1e9 + 7;

public:
    int totalSum(TreeNode* root) {
        if (!root)
            return 0;
        return totalSum(root->left) + totalSum(root->right) + root->val;
    }
    int subTreeSum(TreeNode* root, long long sum, long long currSum,
                   long long& maxProd) {
        if (!root)
            return 0;
        int leftSum = subTreeSum(root->left, sum, currSum, maxProd);
        int rightSum = subTreeSum(root->right, sum, currSum, maxProd);
        currSum = leftSum + rightSum + root->val;
        maxProd = max(maxProd, (sum - currSum) * currSum);
        return currSum;
    }
    int maxProduct(TreeNode* root) {
        sum = totalSum(root), maxProd = 1;
        subTreeSum(root, sum, 0, maxProd);
        return maxProd % MOD;
    }
};