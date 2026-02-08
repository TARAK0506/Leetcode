class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int sum = 0, j;
            for (j = i + 1; j < n; j++) {
                sum += nums[j];
            }
            int avg = sum / (n - i - 1);
            if (nums[i] > avg)
                cnt++;
        }
        return cnt;
    }
};