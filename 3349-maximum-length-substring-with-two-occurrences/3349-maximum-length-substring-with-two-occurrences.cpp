class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0, n = s.length();
        int max_len = 0;
        while (j < n) {
            mp[s[j]]++;
            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }
            max_len = max(max_len, j - i + 1);
            j++;
        }
        return max_len;
    }
};