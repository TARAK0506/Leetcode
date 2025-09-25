class Solution {
public:
    const int MOD = 1e9 + 7;
    int findMax(vector<int>& candies) {
        int maxi = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            if (maxi <= candies[i])
                maxi = candies[i];
        }
        return maxi;
    }
    bool check(vector<int>& candies, int c, long long k) {
        long long cnt = 0;
        for (int i = 0; i < candies.size(); i++) {
            cnt += (long long)candies[i] / (long long)c;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int low = 1, high = findMax(candies);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(candies, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};