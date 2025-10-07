class Solution {
public:
    double check(vector<int>& dist, double hour, double speed) {
        int n = dist.size();
        double total_time = 0;
        for (int i = 0; i < n - 1; i++) {
            total_time += ceil((double)dist[i] / (double)speed);
        }
        total_time += (double)dist[n - 1] / speed;
        return total_time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(), ans = -1;
        int low = 1, high = 1e8;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(dist, hour, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};