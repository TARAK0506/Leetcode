class Solution {
    int m, n, total;

public:
    void shift(vector<vector<int>>& grid, int rows, int cols) {
        while (rows < cols) {
            swap(grid[rows / n][rows % n], grid[cols / n][cols % n]);
            rows++;
            cols--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size(), total = m * n;
        k = k % total;
        shift(grid, 0, total - 1);
        shift(grid, 0, k - 1);
        shift(grid, k, total - 1);
        return grid;
    }
};