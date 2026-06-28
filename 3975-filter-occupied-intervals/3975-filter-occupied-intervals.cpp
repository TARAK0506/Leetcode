#define all(x) begin(x), end(x)
class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        vector<vector<int>> ans, res;
        sort(all(occupiedIntervals));
        ans.emplace_back(occupiedIntervals[0]);
        int n = occupiedIntervals.size();
        for (int i = 1; i < n; i++) {
            vector<int>& last = ans.back();
            if (last[1] < occupiedIntervals[i][0] - 1) {
                ans.emplace_back(occupiedIntervals[i]);
            } else {
                last[1] = max(last[1], occupiedIntervals[i][1]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i][1] < freeStart || ans[i][0] > freeEnd) {
                res.push_back({ans[i][0], ans[i][1]});
                continue;
            }
            if (ans[i][0] < freeStart) {
                res.push_back({ans[i][0], freeStart - 1});
            }
            if (ans[i][1] > freeEnd){
                res.push_back({freeEnd + 1, ans[i][1]});
            }
        }
        return res;
    }
};