class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS;
        for (auto& val : nums) {
            if (LIS.empty() || LIS[LIS.size() - 1] < val) {
                LIS.emplace_back(val);
            } else {
                auto it = lower_bound(LIS.begin(), LIS.end(), val);
                *it = val;
            }
        }
        return LIS.size();
    }
};