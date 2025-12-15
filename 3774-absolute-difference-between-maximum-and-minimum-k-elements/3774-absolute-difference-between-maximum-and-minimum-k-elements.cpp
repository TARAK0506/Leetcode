class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size(), largest = 0, smallest = 0;
        sort(nums.rbegin(), nums.rend());
        int i = 0;
        while (k--) {
            largest += nums[i];
            smallest += nums[n - i - 1];
            i++;
        }
        return abs(largest - smallest);
    }
};