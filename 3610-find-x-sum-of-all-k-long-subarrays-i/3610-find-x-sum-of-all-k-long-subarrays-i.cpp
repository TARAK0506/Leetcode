class Solution {
public:
    int x_sum(unordered_map<int, int> mp, int x) {
        int sum = 0;
        priority_queue<pair<int, int>> pq;
        for (auto& [key, freq] : mp) {
            pq.push({freq, key});
        }
        while (!pq.empty() && x--) {
            auto top = pq.top();
            pq.pop();
            int freq = top.first;
            while (freq--)
                sum += top.second;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int i = 0, j = 0, n = nums.size(), idx = 0;
        vector<int> ans(n - k + 1);
        unordered_map<int, int> mp;
        while (j < n) {
            mp[nums[j]]++;
            while ((j - i + 1) > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            if (j - i + 1 == k) {
                int xsum = x_sum(mp, x);
                ans[idx++] = xsum;
            }
            j++;
        }
        return ans;
    }
};