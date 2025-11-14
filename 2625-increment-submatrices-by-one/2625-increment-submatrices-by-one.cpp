class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (auto& q : queries) {
            int row1 = q[0], row2 = q[2];
            int col1 = q[1], col2 = q[3];
            for (int i = row1; i <= row2; i++) {
                for (int j = col1; j <= col2; j++) {
                    ans[i][j] += 1;
                }
            }
        }
        return ans;
    }
};