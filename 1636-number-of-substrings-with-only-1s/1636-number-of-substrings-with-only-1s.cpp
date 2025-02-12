class Solution {
public:
    int numSub(string s) {
        int l = 0, r = s.length() - 1;
        long long cnt = 0, ans = 0, mod = 1e9 + 7;
        while (l <= r) {
            if (s[l] == '1') {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
            l++;
        }
        return ans % (mod);
    }
};