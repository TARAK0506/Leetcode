class Solution {
    stack<int> st;

public:
    int longestValidParentheses(string s) {
        st.push(-1);
        int maxLen = 0;
        for (int j = 0; j < s.length(); j++) {
            char ch = s[j];
            if (ch == '(') {
                st.push(j);
            } else {
                st.pop();
                if (st.empty())
                    st.push(j);
                else
                    maxLen = max(maxLen, j - st.top());
            }
        }
        return maxLen;
    }
};