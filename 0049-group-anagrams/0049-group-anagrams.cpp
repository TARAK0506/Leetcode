class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(strs[i]);
        }

        for (auto& [key, val] : mp) {
            anagrams.emplace_back(val);
        }
        return anagrams;
    }
};