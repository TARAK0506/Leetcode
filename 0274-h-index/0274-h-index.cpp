class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), ans = 0;
        sort(citations.begin(), citations.end());
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] >= n - i) {
                ans = n - i;
            }
        }
        return ans;
    }
};