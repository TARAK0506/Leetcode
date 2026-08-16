class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = 0, minIdx = -1, minDist = INT_MAX;
        for (auto& drone : drones) {
            int xi = drone[0], yi = drone[1], range = drone[2];
            int dist = abs(xi - target[0]) + abs(yi - target[1]);
            if (dist <= range && dist < minDist) {
                minIdx = idx;
                minDist = dist;
            }
            idx++;
        }
        return minIdx;
    }
};