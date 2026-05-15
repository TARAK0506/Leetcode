class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), maxNum = 0;
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int> a, const vector<int> b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        vector<int> LIS;
        for (auto& envelope : envelopes) {
            int width = envelope[0], height = envelope[1];
            if (LIS.empty() || LIS[LIS.size() - 1] < height) {
                LIS.emplace_back(height);
            } else {
                auto it = lower_bound(LIS.begin(), LIS.end(), height);
                *it = height;
            }
        }
        return LIS.size();
    }
};