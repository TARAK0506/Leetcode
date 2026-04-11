class Solution {
    int n, m;

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = m = grid.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& [key, val] : mp) {
            if (key < 0) {
                sort(val.begin(), val.end());
            } else {
                sort(val.rbegin(), val.rend());
            }
        }
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = mp[i - j][idx[i - j]++];
            }
        }
        return matrix;
    }
};