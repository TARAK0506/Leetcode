class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length(), score = 0, depth = 0;
        char prev = '(';
        stack<int> st;
        vector<int> level(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depth += 1;
                st.push(depth);
            } else {
                int currScore = (prev == '(') ? 1 : 2 * level[depth];
                st.pop();
                if (!st.empty()) {
                    level[st.top()] += currScore;
                } else {
                    score += currScore;
                }
                level[depth] = 0;
                depth -= 1;
            }
            prev = s[i];
        }
        return score;
    }
};