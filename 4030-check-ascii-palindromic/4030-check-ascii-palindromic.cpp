class Solution {
public:
    string decimal2Binary(int num) {
        string s;
        for (int i = 7; i >= 0; i--) {
            s += ((num >> i) & 1) ? '1' : '0';
        }
        return s;
    }
    bool isPalindrome(string& s) {
        int i = 0, n = s.length() - 1;
        while (i < n) {
            if (s[i] != s[n])
                return false;
            i++;
            n--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string str;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            str += decimal2Binary((int)ch);
        }
        return isPalindrome(str);
    }
};