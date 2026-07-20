class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIdx(26, 0);
        vector<bool> seen(26, false);
        for (int i = 0; i < n; i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        stack<char> st;
        string ans;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (seen[ch - 'a'] == true)
                continue;
            while (!st.empty() && st.top() > ch && lastIdx[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            seen[ch - 'a'] = true;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};