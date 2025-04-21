class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, n = s.size();
        int ans = 0;
        unordered_map<char, int> mp = {{'a', 0}, {'b', 0}, {'c', 0}};
        while (right <= n) {
            mp[s[right]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += n - right;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};