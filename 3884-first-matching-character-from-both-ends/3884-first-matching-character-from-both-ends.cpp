class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0, n = s.length() - 1;
        while (i <= n) {
            if (s[i] == s[n])
                return i;
            i++;
            n--;
        }
        return -1;
    }
};