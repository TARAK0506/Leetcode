class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minVal = INT_MAX;
        long long sum = 0, negatives = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int val = matrix[row][col];
                sum += abs(val);
                if (val < 0) {
                    negatives++;
                }
                minVal = min(minVal, abs(val));
            }
        }
        return ((negatives & 1) == 0 ? sum : sum - 2 * minVal);
    }
};