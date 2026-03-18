class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (st.empty())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void dfs(string curr, int n) {
        if (curr.length() == 2 * n) {
            if (isValid(curr))
                ans.emplace_back(curr);
            return;
        }

        dfs(curr + '(', n);

        dfs(curr + ')', n);
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        dfs(curr, n);
        return ans;
    }
};