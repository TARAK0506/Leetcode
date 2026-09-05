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
    int num, dashes;

public:
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length(), idx = 0;
        num = 0, dashes = 0;
        TreeNode* root = nullptr;
        stack<pair<TreeNode*, int>> st;
        while (idx < n) {
            while (idx < n && traversal[idx] == '-') {
                dashes++;
                idx++;
            }
            while (idx < n && isdigit(traversal[idx])) {
                int value = traversal[idx] - '0';
                num = num * 10 + value;
                idx++;
            }
            TreeNode* newNode = new TreeNode(num);
            num = 0;
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
            dashes = 0;
        }
        return root;
    }
};