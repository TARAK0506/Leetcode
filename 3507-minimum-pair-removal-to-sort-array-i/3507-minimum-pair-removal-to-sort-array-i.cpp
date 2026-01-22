class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), idx = -1;
        int minSum = INT_MAX, sum = 0;
        for (int i = 1; i < n; i++) {
            sum = nums[i - 1] + nums[i];
            if (sum < minSum) {
                minSum = sum;
                idx = i - 1;
            }
        }
        return idx;
    }
    bool isSorted(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int minOps = 0;
        while (!isSorted(nums)) {
            minOps++;
            int idx = minPairSum(nums);
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
        }
        return minOps;
    }
};