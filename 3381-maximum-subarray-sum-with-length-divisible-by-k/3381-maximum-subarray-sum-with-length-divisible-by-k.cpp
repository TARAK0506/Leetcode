class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0, maxSum = LLONG_MIN;
        unordered_map<long long, long long> mp;
        mp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int key = (i + 1) % k;
            if (mp.find(key) != mp.end()) {
                maxSum = max(maxSum, currSum - mp[key]);
                mp[key] = min(mp[key], currSum);
            } else {
                mp[key] = currSum;
            }
        }
        return maxSum;
    }
};