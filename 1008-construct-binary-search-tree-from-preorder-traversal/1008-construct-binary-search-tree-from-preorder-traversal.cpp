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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            int curr = preorder[i];
            TreeNode* node = new TreeNode(curr);
            TreeNode* last = nullptr;
            while (!st.empty() && curr > st.top()->val) {
                last = st.top();
                st.pop();
            }
            if (last) {
                last->right = node;
            } else {
                st.top()->left = node;
            }
            st.push(node);
        }
        return root;
    }
};