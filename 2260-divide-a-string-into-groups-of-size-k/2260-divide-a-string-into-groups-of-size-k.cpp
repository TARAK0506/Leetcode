class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            temp += s[i];
            if (temp.size() == k) {
                ans.emplace_back(temp);
                temp = "";
            }
        }
        if (!temp.empty()) {
            while (temp.size() < k) {
                temp += fill;
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};