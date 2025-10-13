class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), ans = 0;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (citations[mid] < n - mid) {
                low = mid + 1;
            } else {
                ans = n - mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};