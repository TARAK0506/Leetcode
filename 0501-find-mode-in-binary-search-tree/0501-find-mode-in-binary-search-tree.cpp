/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        q.push(root);
        int maxFreq = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *curr = q.front();
                q.pop();
                mp[curr->val]++;
                maxFreq = max(maxFreq, mp[curr->val]);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        } 
        vector<int> ans;
        for(auto &it: mp)
          if(it.second == maxFreq) ans.push_back(it.first);
        return ans;
    }
};