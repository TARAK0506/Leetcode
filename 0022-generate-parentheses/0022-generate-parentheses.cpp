class Solution {
    vector<string> parenthesis;

    bool isValid(string& s) {
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

public:
    void dfs(string& curr, int n) {
        if (curr.length() == 2 * n) {
            if (isValid(curr))
                parenthesis.emplace_back(curr);
            return;
        }
        curr += '(';
        dfs(curr, n);
        curr.pop_back();

        curr += ')';
        dfs(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        dfs(curr, n);
        return parenthesis;
    }
};