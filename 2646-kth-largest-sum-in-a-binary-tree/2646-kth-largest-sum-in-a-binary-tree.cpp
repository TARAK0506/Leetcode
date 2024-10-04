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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        if(!root) return sum;
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size = q.size();
          long long levelsum = 0;
          for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            levelsum += curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
          }
          pq.push(levelsum);
        }
        if(pq.size()<k) return -1; 
        while(k>1){
          pq.pop();
          k--;
        }
        return pq.top();
    }
};