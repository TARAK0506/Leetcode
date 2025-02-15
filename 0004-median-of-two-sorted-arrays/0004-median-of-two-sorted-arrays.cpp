class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int l = 0, r = nums1.size() - 1;
        int l1 = 0, r1 = nums2.size() - 1;
        while (l <= r && l1 <= r1) {
            if (nums1[l] <= nums2[l1]) {
                nums.push_back(nums1[l]);
                l++;
            } else {
                nums.push_back(nums2[l1]);
                l1++;
            }
        }
        while (l <= r) {
            nums.push_back(nums1[l]);
            l++;
        }
        while (l1 <= r1) {
            nums.push_back(nums2[l1]);
            l1++;
        }
        int n = nums.size();
        if (n % 2 == 0) {
            return (nums[n/2 - 1] + nums[n/2]) / 2.0;
        } else {
            return nums[n/2];
        }
        return 0;
    }
};