class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        string ans = "";
        for (int i = 0, j = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                int idx = mp[s[i]];
                if(j - idx > k) {
                    mp[s[i]] = j++;
                    ans.push_back(s[i]);
                }
                else{
                    continue;
                }
            } else {
                mp[s[i]] = j++;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};