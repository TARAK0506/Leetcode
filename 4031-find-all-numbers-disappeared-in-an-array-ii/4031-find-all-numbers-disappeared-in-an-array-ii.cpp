class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        int n = nums.size(), curr = lower;
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] < lower || upper < nums[i])
                continue;
            if (curr < nums[i]) {
                ans.push_back({curr, nums[i] - 1});
                curr = nums[i];
            }
            curr = max(curr, nums[i] + 1);
            if (curr > upper) {
                break;
            }
        }
        if (curr <= upper) {
            ans.push_back({curr, upper});
        }
        return ans;
    }
};