class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = k % n;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if ((row & 1) == 0) {
                    if (mat[row][col] != mat[row][(col + k) % n])
                        return false;
                } else {
                    if (mat[row][col] != mat[row][(n + col - k) % n])
                        return false;
                }
            }
        }
        return true;
    }
};