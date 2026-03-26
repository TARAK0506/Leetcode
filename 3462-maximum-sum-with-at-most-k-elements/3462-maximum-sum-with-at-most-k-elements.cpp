class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long n = grid.size(), m = grid[0].size();
        for (int row = 0; row < n; row++) {
            sort(rbegin(grid[row]), rend(grid[row]));
        }
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int noOfEle = limits[i];
            for (int j = 0; j < noOfEle; j++) {
                pq.push(grid[i][j]);
            }
        }
        long long maxSum = 0;
        while (!pq.empty() && k--) {
            maxSum += pq.top();
            pq.pop();
        }
        return maxSum;
    }
};