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
    unordered_map<TreeNode*, TreeNode*> parent;

public:
    TreeNode* markChild2Parent(TreeNode* root, int start) {
        TreeNode* targetNode = nullptr;
        if (!root)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr->val == start) {
                targetNode = curr;
            }
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, bool> isVisited;
        TreeNode* target = markChild2Parent(root, start);
        queue<TreeNode*> q;
        q.push(target);
        isVisited[target] = true;
        int time = 0;
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                if (curr->left && !isVisited[curr->left]) {
                    flag = true;
                    isVisited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !isVisited[curr->right]) {
                    flag = true;
                    isVisited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !isVisited[parent[curr]]) {
                    flag = true;
                    isVisited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            if (flag)
                time++;
        }
        return time;
    }
};