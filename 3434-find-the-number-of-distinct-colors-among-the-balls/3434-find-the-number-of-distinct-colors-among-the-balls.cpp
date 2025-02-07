class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, int> ballcount, colorfreq;
        for (auto& it : queries) {
            int x = it[0];
            int y = it[1];
            if (ballcount.find(x) != ballcount.end()) {
                colorfreq[ballcount[x]]--;
                if (colorfreq[ballcount[x]] == 0)
                    colorfreq.erase(ballcount[x]);
            }
            ballcount[x] = y;
            colorfreq[y]++;
            res.emplace_back(colorfreq.size());
        }
        return res;
    }
};