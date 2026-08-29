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
    int currDepth = 1;

public:
    TreeNode* dfs(TreeNode* root, int val, int currDepth, int depth) {
        if (!root)
            return nullptr;
        if (currDepth == depth - 1) {

            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            root->left = leftNode;
            leftNode->left = leftTemp;

            root->right = rightNode;
            rightNode->right = rightTemp;
            return root;
        }
        TreeNode* leftSubTree = dfs(root->left, val, currDepth + 1, depth);
        TreeNode* rightSubTree = dfs(root->right, val, currDepth + 1, depth);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            root = newnode;
            return root;
        }
        return dfs(root, val, currDepth, depth);
    }
};