class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = num[i];

            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }

            if (!st.empty() || ch != '0')
                st.push(ch);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";
        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());

        return str;
    }
};