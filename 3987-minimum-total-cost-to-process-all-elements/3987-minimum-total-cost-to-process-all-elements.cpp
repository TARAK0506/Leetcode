class Solution {
    const int MOD = 1e9 + 7;

public:
    int minimumCost(vector<int>& nums, int k) {
        long long n = nums.size(), resources = k, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= resources) {
                resources -= nums[i];
            } else {
                long long ops = ((nums[i] - resources) + k - 1) / k;
                resources += ops * k;
                resources -= nums[i];
                ans += ops;
            }
        }

        return ((ans % MOD) * (ans % MOD + 1) / 2) % MOD;
    }
};