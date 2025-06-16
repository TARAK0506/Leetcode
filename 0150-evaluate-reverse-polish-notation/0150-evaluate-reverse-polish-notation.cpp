class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int operand1 = 0, operand2 = 0;
        for (auto ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                operand1 = st.top();
                st.pop();
                operand2 = st.top();
                st.pop();
                if (ch == "+")
                    st.push(operand2 + operand1);
                if (ch == "-")
                    st.push(operand2 - operand1);
                if (ch == "*")
                    st.push(operand2 * operand1);
                if (ch == "/")
                    st.push(operand2 / operand1);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};