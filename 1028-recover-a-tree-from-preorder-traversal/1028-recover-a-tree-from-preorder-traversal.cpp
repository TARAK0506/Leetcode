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
    int n, idx;

public:
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length(), idx = 0;
        TreeNode* root = nullptr;
        stack<pair<TreeNode*, int>> st;
        while (idx < n) {
            int dashes = 0;
            while (idx < n && traversal[idx] == '-') {
                dashes++;
                idx++;
            }
            int num = 0;
            while (idx < n && isdigit(traversal[idx])) {
                int value = traversal[idx] - '0';
                num = num * 10 + value;
                idx++;
            }
            TreeNode* newNode = new TreeNode(num);
            if (!root) {
                root = newNode;
                st.push({newNode, dashes});
                continue;
            }
            while (!st.empty() && st.top().second >= dashes) {
                st.pop();
            }
            TreeNode* parentNode = st.top().first;
            if (!parentNode->left)
                parentNode->left = newNode;
            else
                parentNode->right = newNode;
            st.push({newNode, dashes});
        }
        return root;
    }
};