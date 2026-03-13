class Solution {
public:
    bool check(int mountainHeight, vector<int>& workerTimes,
               long long seconds) {
        long long n = workerTimes.size();
        for (int i = 0; i < n; i++) {
            long long timeSpent = 0;
            long long turn = 1;
            while (true) {
                timeSpent += 1LL * turn * workerTimes[i];
                if (timeSpent > seconds)
                    break;
                mountainHeight--;
                turn++;
                if (mountainHeight <= 0)
                    return true;
            }
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long maxVal = *max_element(begin(workerTimes), end(workerTimes));
        long long low = 0,
                  high = maxVal *
                         (1LL * mountainHeight * (mountainHeight + 1) / 2),
                  ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mountainHeight, workerTimes, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};