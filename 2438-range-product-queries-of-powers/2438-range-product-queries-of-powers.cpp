class Solution {
    const int MOD = 1e9 + 7;
    bool isPowerOfTwo(int n) { return n && (n & (n - 1)) == 0; }
    vector<int> computePower(int n) {
        vector<int> powers;
        for (int i = 0; n > 0; i++) {
            if ((n & 1)) {
                powers.emplace_back(1 << i);
            }
            n >>= 1;
        }
        return !isPowerOfTwo(n) ? powers : vector<int>{n};
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers = computePower(n);
        vector<int> answers;
        for (auto query : queries) {
            int left = query[0], right = query[1];
            long long ans = 1;
            while (left <= right) {
                ans = 1LL * (ans * powers[left]) % MOD;
                left += 1;
            }
            answers.emplace_back(ans);
        }
        return answers;
    }
};