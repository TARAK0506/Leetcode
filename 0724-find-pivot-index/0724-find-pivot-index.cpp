class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), pivotIdx = -1;
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return pivotIdx;
    }
};