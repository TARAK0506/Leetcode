class Solution {
public:
    string generate(int n, char start) {
        string res = "";
        char ch = start;
        for (int i = 0; i < n; i++) {
            res += ch;
            if (res.back() == '0')
                ch = '1';
            else
                ch = '0';
        }
        return res;
    }
    int minOperations(string s) {
        int n = s.length(), minOps = INT_MAX;
        string startZero = generate(n, '0');
        string startOne = generate(n, '1');
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == startZero[i])
                continue;
            else
                cnt0++;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == startOne[i])
                continue;
            else
                cnt1++;
        }
        minOps = min(cnt0, cnt1);
        return minOps;
    }
};