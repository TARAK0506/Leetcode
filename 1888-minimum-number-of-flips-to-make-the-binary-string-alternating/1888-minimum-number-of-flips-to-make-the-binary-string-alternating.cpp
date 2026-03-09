class Solution {
public:
    string generate(int n, char start) {
        string s;
        char ch = start;
        for (int i = 0; i < 2* n; i++) {
            s += ch;
            ch = (ch == '0') ? '1' : '0';
        }
        return s;
    }
    int minFlips(string s) {
        int n = s.length(), minOps = INT_MAX;
        string startZero = generate(n, '0');
        string startOne = generate(n, '1');
        string str = s + s;
        int i = 0, j = 0, len = 2 * n;
        int ops0 = 0, ops1 = 0;
        while (j < len) {
            if (str[j] != startOne[j]) {
                ops1++;
            }
            if (str[j] != startZero[j]) {
                ops0++;
            }
            if (j - i + 1 > n) {
                if (str[i] != startOne[i])
                    ops1--;
                if (str[i] != startZero[i])
                    ops0--;
                i++;
            }
            if (j - i + 1 == n) {
                minOps = min({minOps, ops1, ops0});
            }
            j++;
        }
        return minOps;
    }
};