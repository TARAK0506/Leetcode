class Solution {
public:
    bool isAnagram(string a, string b) {
        if (a.length() != b.length())
            return false;
        unordered_map<char, int> mp;
        for (auto& ch : a) {
            mp[ch]++;
        }
        for (auto& ch : b) {
            mp[ch]--;
            if (mp[ch] < 0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.emplace_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (!isAnagram(words[i], ans.back())) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};