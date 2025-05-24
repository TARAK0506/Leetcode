class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            string str = words[i];
            if (str.find(x) != string::npos) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};