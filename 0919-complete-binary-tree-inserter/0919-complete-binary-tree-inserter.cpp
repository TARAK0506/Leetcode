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
class CBTInserter {
    TreeNode* root = nullptr;
    queue<TreeNode*> q;
    deque<TreeNode*> dq;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (!curr->left || !curr->right) {
                dq.push_back(curr);
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    int insert(int val) {
        TreeNode* node = dq.front();
        dq.push_back(new TreeNode(val));
        if (!node->left) {
            node->left = dq.back();
        } else {
            node->right = dq.back();
            dq.pop_front();
        }
        return node->val;
    }

    TreeNode* get_root() { 
        return root; 
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */