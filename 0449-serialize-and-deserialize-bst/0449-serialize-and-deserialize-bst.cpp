/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  6,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1,
class Codec {
private:
    TreeNode* buildTree(stringstream& ss) {
        string s;
        if (!getline(ss, s, ','))
            return nullptr;
        if (s == "-1")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(ss);
        root->right = buildTree(ss);
        return root;
    }

    void preOrder(TreeNode* root, string& str) {
        if (!root) {
            str += "-1,";
            return;
        }
        str += to_string(root->val) + ",";
        preOrder(root->left, str);
        preOrder(root->right, str);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (!root)
            return "";
        preOrder(root, str);
        // cout << str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;