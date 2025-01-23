class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size(), count = 0;
        int left = 0, right = 0, end = n;
        unordered_map<char, int> mp;
        while (right < end) {
            mp[s[right]]++;
            while (mp[s[right]] >= k) {
                count += n - right;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};