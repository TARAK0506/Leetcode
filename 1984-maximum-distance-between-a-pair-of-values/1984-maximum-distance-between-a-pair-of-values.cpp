class Solution {
public:
    int binarySearch(vector<int>& nums2, int target) {
        int n = nums2.size(), idx = 0;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums2[mid] < target) {
                high = mid - 1;
            } else if (nums2[mid] >= target) {
                idx = mid;
                low = mid + 1;
            }
        }
        return idx;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), maxDistance = INT_MIN, j = 0;
        for (int i = 0; i < n; i++) {
            int ele = nums1[i];
            j = binarySearch(nums2, ele);
            maxDistance = max(maxDistance, j - i);
        }
        return maxDistance;
    }
};