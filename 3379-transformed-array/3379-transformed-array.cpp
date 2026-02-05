class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                arr[i] = nums[(i + nums[i]) % n];
            } else {
                arr[i] = nums[(i + n + nums[i] % n) % n];
            }
        }
        return arr;
    }
};