class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (abs((int)s[i - 1] - (int)s[i]) > 2)
                return false;
        }
        return true;
    }
};