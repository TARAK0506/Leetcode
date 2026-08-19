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
    vector<int> nodes;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while (true) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                if (st.empty())
                    break;
                auto node = st.top();
                st.pop();
                nodes.emplace_back(node->val);
                curr = node->right;
            }
        }
        return nodes;
    }
};