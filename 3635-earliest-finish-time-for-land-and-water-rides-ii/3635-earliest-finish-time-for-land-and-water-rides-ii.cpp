class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int landFinishTime = INT_MAX, ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            landFinishTime =
                min(landFinishTime, (landStartTime[i] + landDuration[i]));
        }
        int waterFinishTime = INT_MAX;
        for (int j = 0; j < m; j++) {
            waterFinishTime =
                min(waterFinishTime, (waterStartTime[j] + waterDuration[j]));
            ans = min(ans, max(landFinishTime, waterStartTime[j]) +
                               waterDuration[j]);
        }
        for (int i = 0; i < n; i++) {
            ans = min(ans,
                      max(waterFinishTime, landStartTime[i]) + landDuration[i]);
        }
        return ans;
    }
};