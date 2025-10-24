class Solution {
public:
    bool check(string& s) {
        if (s[0] == s[1])
            return true;
        return false;
    }
    string solve(string str) {
        if (str.size() == 2)
            return str;
        string reduced_str = "";
        for (int i = 0; i < str.length() - 1; i++) {
            int sum = (str[i] - '0' + str[i + 1] - '0') % 10;
            reduced_str += sum + '0';
        }
        return solve(reduced_str);
    }
    bool hasSameDigits(string s) {
        string str = solve(s);
        return check(str);
    }
};