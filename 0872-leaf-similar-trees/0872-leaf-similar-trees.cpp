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
    bool isLeaf(TreeNode* root) { 
        return root && !root->left && !root->right; 
    }
    void inOrder(TreeNode* root, vector<int>& nodes) {
        if(!root) return ;
        if (isLeaf(root)) {
            nodes.emplace_back(root->val);
            return;
        }
        inOrder(root->left, nodes);
        inOrder(root->right, nodes);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        inOrder(root1, arr1);
        inOrder(root2, arr2);
        if (arr1.size() != arr2.size())
            return false;
        int n = arr1.size();
        for (int i = 0; i < n; i++) {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};