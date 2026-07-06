class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), cnt = 0;
        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int previousEnd = INT_MIN;
        for (auto& it : intervals) {
            if (previousEnd < it[1]) {
                previousEnd = it[1];
                cnt++;
            }
        }
        return cnt;
    }
};