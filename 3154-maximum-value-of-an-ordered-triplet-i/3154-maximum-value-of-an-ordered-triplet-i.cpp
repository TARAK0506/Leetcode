class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    maxx = max(maxx, (long long) (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return maxx;
    }
};