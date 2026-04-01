class Solution {
    int m, n;

public:
    void flipRows(vector<vector<int>>& grid, int row) {
        for (int i = 0; i < n; i++) {
            grid[row][i] = 1 - grid[row][i];
        }
    }

    void flipCols(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < m; i++) {
            grid[i][col] = 1 - grid[i][col];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 0) {
                flipRows(grid, row);
            }
        }

        for (int col = 1; col < n; col++) {
            int cntOnes = 0, cntZeros = 0;
            for (int row = 0; row < m; row++) {
                if (grid[row][col] == 1)
                    cntOnes++;
                else
                    cntZeros++;
            }
            if (cntZeros > cntOnes) {
                flipCols(grid, col);
            }
        }

        int ans = 0;

        for (int row = 0; row < m; row++) {
            int sum = 0, power = 0;
            for (int col = n - 1; col >= 0; col--) {
                sum += grid[row][col] * (1 << power);
                power++;
            }
            ans += sum;
        }
        return ans;
    }
};