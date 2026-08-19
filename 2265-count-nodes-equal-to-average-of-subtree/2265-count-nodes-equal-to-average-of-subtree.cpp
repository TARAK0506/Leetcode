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
    int sum;
    int noOfNodes;
    int avg;
};
class Solution {
    int cnt;

public:
    Node dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0, 0};
            
        auto leftSubTree = dfs(root->left);
        auto rightSubTree = dfs(root->right);

        int sum = leftSubTree.sum + rightSubTree.sum + root->val;
        int noOfNodes = leftSubTree.noOfNodes + rightSubTree.noOfNodes + 1;
        int avg = sum / noOfNodes;
        if (root->val == avg)
            cnt++;
        return {sum, noOfNodes, avg};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        dfs(root);
        return cnt;
    }
};