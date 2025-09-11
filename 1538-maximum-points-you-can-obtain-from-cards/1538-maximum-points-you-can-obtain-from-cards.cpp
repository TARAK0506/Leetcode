class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefixSum(k + 1, 0);
        vector<int> suffixSum(k + 1, 0);
        for(int i = 0; i < k; i++){
            prefixSum[i+1] = prefixSum[i] + cardPoints[i];
            suffixSum[i+1] = suffixSum[i] + cardPoints[n - i - 1];
        }
        int maxSum = 0;
        for (int i = 0; i <= k; i++) {
            int sum = prefixSum[i] + suffixSum[k - i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};