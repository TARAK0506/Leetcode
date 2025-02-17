/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            ans.emplace_back(node->val);
            st.pop();
            for (auto it : node->children) {
                if (it)
                    st.push(it);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};