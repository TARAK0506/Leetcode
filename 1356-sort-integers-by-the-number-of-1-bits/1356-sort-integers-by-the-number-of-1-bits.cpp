class Solution {
public:
    int countSetBits(int num) {
        int cnt = 0;
        while (num > 0) {
            num &= (num - 1);
            cnt++;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int count = countSetBits(arr[i]);
            mp[arr[i]] = count;
        }
        auto freq = [&mp](const auto& a, const auto& b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] < mp[b];
        };
        sort(arr.begin(), arr.end(), freq);
        return arr;
    }
};