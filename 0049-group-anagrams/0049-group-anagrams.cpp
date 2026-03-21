class Solution {
public:
    string generate(string& s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        string str = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                str += string(freq[i], i + 'a');
            }
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            temp = generate(temp);
            mp[temp].push_back(strs[i]);
        }

        for (auto& [key, val] : mp) {
            anagrams.emplace_back(val);
        }
        return anagrams;
    }
};