class Solution {
    int n;
    vector<int> ans;

public:
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high,
               vector<int>& ans) {
        vector<pair<int, int>> temp(high - low + 1);
        int idx = 0, left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left].first <= arr[right].first) {
                temp[idx++] = arr[right++];
            } else {
                ans[arr[left].second] += (high - right + 1);
                temp[idx++] = arr[left++];
            }
        }

        while (left <= mid) {
            temp[idx++] = arr[left++];
        }
        while (right <= high) {
            temp[idx++] = arr[right++];
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void mergeSort(vector<pair<int, int>>& arr, int low, int high,
                   vector<int>& ans) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);
        merge(arr, low, mid, high, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        ans.assign(n, 0);
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }
};