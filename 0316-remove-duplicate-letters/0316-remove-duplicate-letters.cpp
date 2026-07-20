class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastIdx(26, 0);
        vector<int> seen(26, false);
        for (int i = 0; i < n; i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (seen[ch - 'a'])
                continue;
            while (!ans.empty() && ch < ans.back() && lastIdx[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            seen[ch - 'a'] = true;
        }
        return ans;
    }
};