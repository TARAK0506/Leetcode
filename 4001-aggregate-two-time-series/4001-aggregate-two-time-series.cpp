class Solution {
    int n, m;

public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        n = series1.size(), m = series2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < n && j < m) {
            int summedValue = 0;
            if (series1[i][0] == series2[j][0]) {
                summedValue = series1[i][1] + series2[j][1];
                ans.push_back({series1[i][0], summedValue});
                i++;
                j++;
            } else if (series1[i][0] < series2[j][0]) {
                summedValue = series1[i][1] + series2[j][1];
                ans.push_back({series1[i][0], summedValue});
                i++;
            } else {
                summedValue = series1[i][1] + series2[j][1];
                ans.push_back({series2[j][0], summedValue});
                j++;
            }
        }

        while (i < n) {
            int summedValue = series1[i][1];
            ans.push_back({series1[i][0], summedValue});
            i++;
        }
        while (j < m) {
            int summedValue = series2[j][1];
            ans.push_back({series2[j][0], summedValue});
            j++;
        }
        return ans;
    }
};