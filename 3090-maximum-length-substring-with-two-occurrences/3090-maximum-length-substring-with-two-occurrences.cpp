class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length(), maxLen = 0;
        unordered_map<char, int> mpp;
        int i = 0, j = 0;
        while (j < n) {
            mpp[s[j]]++;
            while (mpp[s[j]] > 2) {
                mpp[s[i]]--;
                i++;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};