class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), prefixSum = nums[0];
        set<int> s(nums.begin(), nums.end());
        int i = 1;
        while (i < n) {
            if ((nums[i] - 1 == nums[i - 1])) {
                prefixSum += nums[i];
                i++;
            } else
                break;
        }
        while (s.find(prefixSum) != s.end())
            prefixSum++;
        return prefixSum;
    }
};