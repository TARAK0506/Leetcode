class Solution {
public:
    int maxDifference(string s) {
        int odd_freq = INT_MIN, even_freq = INT_MAX;
        unordered_map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        for (auto it : mp) {
            if (it.second % 2 != 0)
                odd_freq = max(odd_freq, it.second);
            else
                even_freq = min(even_freq, it.second);
        }
        return odd_freq - even_freq;
    }
};