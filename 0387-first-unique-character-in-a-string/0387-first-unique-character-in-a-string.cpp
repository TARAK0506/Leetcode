class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length(), ans = -1;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};