class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                arr.emplace_back(i);
            }
        }
        sort(arr.begin(), arr.end());
        return arr.size() < k ? -1 : arr[k - 1];
    }
};