class Solution {
public:
    int minElementFreq(string s) {
        char ch =
            *min_element(s.begin(), s.end(),
                         [&](const auto& a, const auto& b) { return a < b; });
        return count(s.begin(), s.end(), ch);
    }
    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        vector<int> ans;
        for (auto& query : queries) {
            int queryFreq = minElementFreq(query);
            int cnt = 0;
            for (auto& word : words) {
                int wordFreq = minElementFreq(word);
                if (queryFreq < wordFreq) {
                    cnt++;
                }
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};