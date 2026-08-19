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
    TreeNode* buildTree(int low, int high, vector<int>& nums) {
        TreeNode* root = nullptr;

        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;
        root = new TreeNode(nums[mid]);
        root->left = buildTree(low, mid - 1, nums);
        root->right = buildTree(mid + 1, high, nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildTree(0, n - 1, nums);
    }
};