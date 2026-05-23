class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), zeros = 0, minSwaps = 0;
        for (auto& num : nums) {
            if (num == 0)
                zeros++;
        }
        int idx = n - zeros;
        for (int i = idx; i < n; i++) {
            if (nums[i] != 0)
                minSwaps++;
        }
        return minSwaps;
    }
};