class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        int n = s.length();
        string res = "";
        unordered_map<char, int> mp;
        unordered_map<char, int> pos;
        int idx = 0;
        for (auto& ch : s) {
            if (isVowel(ch)) {
                mp[ch]++;
                if (pos.find(ch) == pos.end())
                    pos[ch] = idx;
            }
            idx++;
        }
        vector<pair<char, int>> freq;
        for (auto& [key, val] : mp) {
            freq.push_back({key, val});
        }
        sort(freq.begin(), freq.end(), [&](const auto& a, const auto& b) {
            if (a.second != b.second)
                return a.second > b.second;
            return pos[a.first] < pos[b.first];
        });
        string str = "";
        for (auto& it : freq) {
            str += string(it.second, it.first);
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!isVowel(ch))
                res += ch;
            else {
                res += str[index];
                index++;
            }
        }
        return res;
    }
};