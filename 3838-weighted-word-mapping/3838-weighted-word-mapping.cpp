class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s;
        for (auto& word : words) {
            int sum = 0;
            for (int i = 0; i < word.length(); i++) {
                char ch = word[i];
                int idx = ch - 'a';
                sum += (weights[idx]);
            }
            sum %= 26;
            s.push_back(25 - sum + 'a');
        }
        return s;
    }
};