class Solution {
public:
    bool check(vector<int>& position, int distance, int m) {
        int n = position.size(), cnt = 1;
        int prev = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - prev >= distance) {
                cnt++;
                prev = position[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position[0];
        while (low <= high) {
            int mid = midpoint(low, high);
            if (check(position, mid, m))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};