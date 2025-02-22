class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, j = 0, n = s.length(), len = spaces.size();
        while (j < n) {
            if (i < len && j == spaces[i]) {
                ans += " ";
                i++;
            }
            ans += s[j];
            j++;
        }
        return ans;
    }
};