class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp((high - low + 1), 0);
        int idx = 0, left = low, right = mid + 1;
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
        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};