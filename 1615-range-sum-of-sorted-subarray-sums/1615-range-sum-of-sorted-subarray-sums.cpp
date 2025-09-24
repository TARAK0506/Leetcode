class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        long long sum = 0;
        vector<long long> arr;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                arr.emplace_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        vector<long long> prefixSum(arr.size() + 1, 0);
        for (int i = 1; i <= arr.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
        return (prefixSum[right] - prefixSum[left - 1]) % MOD;
    }
};