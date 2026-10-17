class Solution {
    int m, n;
    vector<vector<int>> prefix;

public:
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] -
                  prefix[row1][col2 + 1] + prefix[row1][col1];
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int row1 = i - k >= 0 ? i - k : 0;
                int col1 = j - k >= 0 ? j - k : 0;

                int row2 = i + k < m ? i + k : m - 1;
                int col2 = j + k < n ? j + k : n - 1;
                answer[i][j] = sumRegion(row1, col1, row2, col2);
            }
        }
        return answer;
    }
};