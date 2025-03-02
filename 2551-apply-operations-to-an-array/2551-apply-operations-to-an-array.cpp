class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }
        int j = 0, zeros = 0;
        while (j < n) {
            if (nums[j] != 0) {
                ans.emplace_back(nums[j]);
            } else
                zeros++;
            j++;
        }
        while (zeros--) {
            ans.emplace_back(0);
        }
        return ans;
    }
};