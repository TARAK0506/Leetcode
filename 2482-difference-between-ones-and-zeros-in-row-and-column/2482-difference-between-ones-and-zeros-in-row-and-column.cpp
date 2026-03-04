class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n, 0));
        vector<int> onesRow(m, 0), onesCol(n, 0);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                onesRow[row] += grid[row][col];
                onesCol[col] += grid[row][col];
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                diff[row][col] = onesRow[row] + onesCol[col] -
                                 (m - onesRow[row]) - (n - onesCol[col]);
            }
        }
        return diff;
    }
};