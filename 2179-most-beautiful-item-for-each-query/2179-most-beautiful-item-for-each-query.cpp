class Solution {
public:
    int binarySearch(vector<vector<int>>& items, int ele) {
        int n = items.size();
        int low = 0, high = n - 1;
        int maxVal = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int price = items[mid][0], beauty = items[mid][1];
            if (price > ele) {
                high = mid - 1;
            } else {
                maxVal = max(maxVal, beauty);
                low = mid + 1;
            }
        }
        return maxVal;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        sort(items.begin(), items.end());
        int maxBeauty = 0;
        for (auto& it : items) {
            maxBeauty = max(maxBeauty, it[1]);
            it[1] = maxBeauty;
        }
        vector<int> ans(n, 0);
        for (int j = 0; j < n; j++) {
            int ele = queries[j];
            int maxVal = binarySearch(items, ele);
            ans[j] = maxVal;
        }
        return ans;
    }
};