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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*>dq;
        dq.push_back(root);
        int level = 0;
        while(!dq.empty()){
          int size = dq.size();
          vector<int>levelorder;
          for(int i=0;i<size;i++){
            if(level%2==0){
                TreeNode* curr= dq.back();
                dq.pop_back();
                levelorder.push_back(curr->val);
                if(curr->left) dq.push_front(curr->left);
                if(curr->right) dq.push_front(curr->right);
            }
            else{
                TreeNode* curr= dq.front();
                dq.pop_front();
                levelorder.push_back(curr->val);
                if(curr->right) dq.push_back(curr->right);
                if(curr->left) dq.push_back(curr->left);
            }
          }
          ans.emplace_back(levelorder);
          level++;
        }
        return ans;
    }
};