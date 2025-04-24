class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_set<int> st;
        for (auto& it : nums) {
            st.insert(it);
        }
        int k = st.size();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() == k) {
                ans += (n - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
