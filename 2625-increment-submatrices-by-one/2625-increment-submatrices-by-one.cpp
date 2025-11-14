class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffArray(n, vector<int>(n, 0));
        for (auto& q : queries) {
            int row1 = q[0], row2 = q[2];
            int col1 = q[1], col2 = q[3];

            diffArray[row1][col1] += 1;

            if (col2 + 1 < n)
                diffArray[row1][col2 + 1] -= 1;

            if (row2 + 1 < n)
                diffArray[row2 + 1][col1] -= 1;

            if (row2 + 1 < n && col2 + 1 < n)
                diffArray[row2 + 1][col2 + 1] += 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diffArray[i][j] += diffArray[i][j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                diffArray[i][j] += diffArray[i - 1][j];
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = diffArray[i][j];
            }
        }
        return ans;
    }
};
