class Solution {
public:
    bool ispalindrome(string& str) {
        int n = str.length() - 1;
        int i = 0, j = n;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++) {
            string curr = "";
            for (int j = i; j < n; j++) {
                curr += s[j];
                if (ispalindrome(curr)) {
                    temp = s.substr(i, (j - i + 1));
                    if (temp.length() >= ans.length()) {
                        ans = temp;
                        temp = "";
                    }
                }
            }
        }
        return ans;
    }
};