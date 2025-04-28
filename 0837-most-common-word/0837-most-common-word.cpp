class Solution {
public:
    string toLowerCase(const string& paragraph) {
        string result;
        for (char c : paragraph) {
            if (isalpha(c))
                result += tolower(c);
            else
                result += ' ';
        }
        return result;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans = "";
        paragraph = toLowerCase(paragraph);
        stringstream ss(paragraph);
        string words;
        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> mp;
        while (ss >> words) {
            if (st.find(words) != st.end()) {
                continue;
            } else
                mp[words]++;
        }
        int maxi = 0;
        for (auto& it : mp) {
            if (it.second > maxi) {
                ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};