using ll = long long;
class Solution {
    ll n, validCnt;

public:
    long long countValidSubstrings(string s) {
        n = s.length(), validCnt = 0;
        ll i = 0, j = 0;
        while (j < n) {
            if (j >= 2 && s[j - 2] == 'a' && s[j - 1] == 'b' && s[j] == 'c') {
                i = max(i, j - 1);
            }
            validCnt += (j - i + 1);
            j += 1;
        }
        return validCnt;
    }
};