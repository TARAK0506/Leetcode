class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int mid) {
        long long n = nums.size(), total_ops = 0;
        for (int i = 0; i < n; i++) {
            int ops = nums[i] / mid;
            if (nums[i] % mid == 0) {
                ops -= 1;
            }
            total_ops += ops;
        }
        return total_ops <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};