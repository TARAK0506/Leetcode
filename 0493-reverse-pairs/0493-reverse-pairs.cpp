class Solution {
    int n, cntPairs;
    vector<int> arr;

public:
    void merge(int low, int mid, int high, vector<int>& nums, int& cntPairs) {

        int left = low, right = mid + 1, idx = 0;
        while (left <= mid) {
            while (right <= high && nums[left] > 2 * (long long)nums[right])
                right++;
            cntPairs += (right - (mid + 1));
            left++;
        }

        vector<int> temp((high - low + 1), 0);
        left = low, right = mid + 1, idx = 0;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[idx++] = nums[left++];
            } else {
                temp[idx++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[idx++] = nums[left++];
        }

        while (right <= high) {
            temp[idx++] = nums[right++];
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(int low, int high, vector<int>& nums, int& cntPairs) {
        if (low >= high)
            return;
        int mid = (low + high) >> 1;
        mergeSort(low, mid, nums, cntPairs);
        mergeSort(mid + 1, high, nums, cntPairs);
        merge(low, mid, high, nums, cntPairs);
    }
    int reversePairs(vector<int>& nums) {
        n = nums.size(), cntPairs = 0;
        mergeSort(0, n - 1, nums, cntPairs);
        return cntPairs;
    }
};