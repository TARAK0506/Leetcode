class Solution {
public:
    long long findMax(vector<int>& ranks) {
        long long maxi = LLONG_MIN;
        for (auto& num : ranks) {
            if (maxi < num) {
                maxi = num;
            }
        }
        return maxi;
    }
    bool check(vector<int>& ranks, long long mid, long long cars) {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++) {
            if (ranks[i] == 0)
                continue;
            cnt += (long long)sqrt((double)mid / (double)ranks[i]);
            if (cnt >= cars)
                return true;
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = findMax(ranks) * cars * cars, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(ranks, mid, cars)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};