class Solution {
    int m, n;

public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        map<int, vector<int>> mp;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                mp[row - col].push_back(mat[row][col]);
            }
        }

        for (auto& [key, val] : mp) {
            sort(begin(val), end(val));
            reverse(begin(val), end(val));
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                grid[row][col] = mp[row - col].back();
                mp[row - col].pop_back();
            }
        }
        return grid;
    }
};