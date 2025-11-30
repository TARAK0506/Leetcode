class Solution {
public:
    int maxDistinct(string s) {
        int n = s.length(), ans = 0;
        vector<int> freq(26, 0);
        for (auto& ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 1)
                ans++;
        }
        return ans;
    }
};