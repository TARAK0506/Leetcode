class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> product(n, vector<int>(m));
        long long prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                product[i][j] = prefix % MOD;
                prefix = (prefix * grid[i][j] % MOD) % MOD;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                product[i][j] = (product[i][j] * suffix % MOD) % MOD;
                suffix = (suffix * grid[i][j] % MOD) % MOD;
            }
        }
        return product;
    }
};