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
    int cnt = 0;
public:
    void dfs(TreeNode* root, long long sum, long long target){
        if(!root) return ;
        
        sum += root->val;
        if(sum == target) cnt++;
        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            dfs(curr, 0, targetSum);
            if (curr->left)
                st.push(curr->left);
            if (curr->right)
                st.push(curr->right);
        }
        return cnt;
    }
};