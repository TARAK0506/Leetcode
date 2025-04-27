class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int window_len = 3, cnt = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (j - i + 1 > window_len) {
                i++;
            }
            if (j - i + 1 == window_len) {
                double second = nums[i + 1] / 2.0;
                if (nums[i] + nums[j] == second)
                    cnt++;
            }
            j++;
        }
        return cnt;
    }
};