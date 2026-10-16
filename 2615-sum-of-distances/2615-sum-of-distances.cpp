class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> arr(n, 0LL);
        for (auto& [ele, list] : mp) {
            int m = list.size();
            vector<long long> prefix(m + 1, 0LL);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + list[i];
            }
            for (int i = 0; i < m; i++) {
                long long left = 1LL * i * list[i] - prefix[i];
                long long right =
                    (prefix[m] - prefix[i + 1]) - 1LL * (m - i - 1) * list[i];
                arr[list[i]] = left + right;
            }
        }
        return arr;
    }
};