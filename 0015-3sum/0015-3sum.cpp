class Solution {
public:
    vector<vector<int>> triplets;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int i = 0, n = nums.size();
        if (n < 3)
            return {};
        while (i < n - 2) {
            int j = i + 1;
            int k = n - 1;
            if (i > 0 && nums[i - 1] == nums[i]) {
                i++;
                continue;
            }
            int target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k - 1] == nums[k])
                        k--;
                    j++;
                    k--;
                }
            }
            i++;
        }
        return triplets;
    }
};