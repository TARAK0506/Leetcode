#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size(), maxScore = LLONG_MIN;;
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        vector<int> suffixMin(n, 0);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            long long score = prefixSum[i] - suffixMin[i + 1];
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
