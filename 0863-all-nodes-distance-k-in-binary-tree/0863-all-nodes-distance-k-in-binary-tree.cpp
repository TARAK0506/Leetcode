/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    vector<int> ans;

public:
    void markChild2Parent(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> isVisited;
        markChild2Parent(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        isVisited[target] = true;
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            if (distance == k)
                break;
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr->left && !isVisited[curr->left]) {
                    isVisited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !isVisited[curr->right]) {
                    isVisited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !isVisited[parent[curr]]) {
                    isVisited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            distance++;
        }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            ans.emplace_back(curr->val);
        }
        return ans;
    }
};