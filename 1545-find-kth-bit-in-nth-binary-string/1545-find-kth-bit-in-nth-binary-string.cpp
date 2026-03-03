class Solution {
public:
    string invertStr(string str) {
        int n = str.length();
        for (int i = 0; i < n; i++) {
            str[i] = (str[i] == '0' ? '1' : '0');
        }
        return str;
    }
    string funSn(int n) {
        if (n == 1)
            return "0";
        string prev = funSn(n - 1);
        string invert = invertStr(prev);
        reverse(invert.begin(), invert.end());
        return prev + "1" + invert;
    }
    char findKthBit(int n, int k) {
        string str = funSn(n);
        return str[k - 1];
    }
};