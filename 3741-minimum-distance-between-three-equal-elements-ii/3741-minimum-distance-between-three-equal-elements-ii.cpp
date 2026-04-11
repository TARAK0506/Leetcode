class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), minDist = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [key, freq] : mp) {
            if (freq.size() >= 3) {
                for (int i = 2; i < freq.size(); i++) {
                    minDist = min(minDist, abs(freq[i - 2] - freq[i - 1]) +
                                               abs(freq[i - 1] - freq[i]) +
                                               abs(freq[i] - freq[i - 2]));
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};