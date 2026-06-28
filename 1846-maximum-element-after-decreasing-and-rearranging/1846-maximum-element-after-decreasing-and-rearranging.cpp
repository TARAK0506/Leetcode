#define all(x) sort(begin(x), end(x))
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        all(arr);
        int n = arr.size();
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            arr[i] = abs(arr[i] - arr[i - 1] <= 1) ? arr[i] : arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};