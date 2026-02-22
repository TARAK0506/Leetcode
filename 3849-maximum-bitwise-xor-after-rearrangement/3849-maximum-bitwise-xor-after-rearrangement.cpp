class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        string str = "";
        int cntZeros = 0, cntOnes = 0;
        for (auto& ch : t) {
            if (ch == '0')
                cntZeros++;
            else
                cntOnes++;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (cntOnes > 0) {
                    str += '1';
                    cntOnes--;
                } else {
                    str += '0';
                    cntZeros--;
                }
            } else {
                if (cntZeros > 0) {
                    str += '1';
                    cntZeros--;
                } else {
                    str += "0";
                    cntOnes--;
                }
            }
        }
        return str;
    }
};