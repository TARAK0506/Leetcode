class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        for(int i = 1; i < n; i++){
            int leftSum = prefixSum[i];
            int rightSum = prefixSum[n] -  prefixSum[i];
            // cout << leftSum <<" " << rightSum <<"\n";
            if((leftSum - rightSum) % 2 == 0) cnt++;
        }
        return cnt;
    }
};