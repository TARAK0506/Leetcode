class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        vector<int> rowSum(m, 0), colSum(n, 0);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                rowSum[row] += mat[row][col];
                colSum[col] += mat[row][col];
            }
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col]) {
                    if (rowSum[row] == 1 && colSum[col] == 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};