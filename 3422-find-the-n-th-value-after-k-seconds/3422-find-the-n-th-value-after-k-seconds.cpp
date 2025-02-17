class Solution {
public:
    vector<long long> prefix(vector<long long>& vec, long long i) {
        long long n = vec.size();
        const long long MOD = 1e9 + 7;
        vector<long long> prefixsum(n);
        prefixsum[0] = vec[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = (prefixsum[i - 1] + vec[i]) % MOD;
        }
        return prefixsum;
    }
    int valueAfterKSeconds(int n, int k) {
        vector<long long> vec(n, 1);
        const long long MOD = 1e9 + 7;
        for (int i = 0; i < k; i++) {
            vec = prefix(vec, i);
        }
        return vec[n - 1];
    }
};