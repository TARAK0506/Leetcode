class Solution {
public:
    void dfs(TreeNode* root, TreeNode* parent, int target, int level,
             TreeNode*& foundParent, int& depth) {
        if (!root)
            return;

        if (root->val == target) {
            foundParent = parent;
            depth = level;
            return;
        }

        dfs(root->left, root, target, level + 1, foundParent, depth);
        dfs(root->right, root, target, level + 1, foundParent, depth);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *parentX = nullptr, *parentY = nullptr;
        int depthX = -1, depthY = -1;

        dfs(root, nullptr, x, 0, parentX, depthX);
        dfs(root, nullptr, y, 0, parentY, depthY);

        return depthX == depthY && parentX != parentY;
    }
};