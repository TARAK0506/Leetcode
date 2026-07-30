class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = logs[0][0], time = logs[0][1], maxTime = time, ans = id;
        for (int i = 1; i < logs.size(); i++) {
            int currId = logs[i][0];
            if ((logs[i][1] - logs[i - 1][1]) > maxTime) {
                maxTime = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            } else if ((maxTime == logs[i][1] - logs[i - 1][1]) &&
                       ans > currId) {
                ans = currId;
            }
        }
        return ans;
    }
};