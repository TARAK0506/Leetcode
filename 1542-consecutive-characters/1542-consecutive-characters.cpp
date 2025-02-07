class Solution {
public:
    int maxPower(string s) {
        int maxi = 1, cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                cnt++;
            else
                cnt = 1;
            if (maxi < cnt)
                maxi = cnt;
        }
        return maxi;
    }
};