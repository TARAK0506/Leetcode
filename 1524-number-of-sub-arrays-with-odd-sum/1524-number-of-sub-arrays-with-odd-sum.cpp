class Solution {
    const int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        long long n = arr.size(), cnt = 0, prefixSum = 0;
        unordered_map<long long, long long> mp;
        long long i = 0, totalSubarrays = n * (n + 1) / 2;
        while (i < n) {
            prefixSum += arr[i];
            prefixSum = prefixSum % 2;
            if (prefixSum == 0)
                cnt += 1;
            if (mp.find(prefixSum) != mp.end()) {
                cnt += mp[prefixSum];
            }
            mp[prefixSum] += 1;
            i += 1;
        }
        cnt = totalSubarrays - cnt;
        return cnt % MOD;
    }
};