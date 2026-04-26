class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1)
            return nums;
        vector<int> maxLeft(n, 0), maxRight(n, 0);
        maxLeft[0] = nums[0], maxRight[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
            maxRight[n - i - 1] = max(maxRight[n - i], nums[n - i - 1]);
        }
        vector<int> valid;
        valid.emplace_back(nums[0]);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > maxLeft[i - 1] || nums[i] > maxRight[i + 1]) {
                valid.emplace_back(nums[i]);
            }
        }
        valid.emplace_back(nums[n - 1]);
        return valid;
    }
};