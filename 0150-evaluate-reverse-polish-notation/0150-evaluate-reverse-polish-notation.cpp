class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a = 0, b = 0;
        for (auto ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                if (ch == "+")
                    st.push(b + a);
                if (ch == "-")
                    st.push(b - a);
                if (ch == "*")
                    st.push(b * a);
                if (ch == "/")
                    st.push(b / a);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};