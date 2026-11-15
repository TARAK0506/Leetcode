class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int minEle = INT_MAX, bitwise_And = nums[i];
            for (int j = i; j < n; j++) {
                if (minEle >= nums[j]) {
                    minEle = nums[j];
                }
                bitwise_And &= nums[j];
                if (bitwise_And == minEle)
                    cnt += 1;
            }
        }
        return cnt;
    }
};