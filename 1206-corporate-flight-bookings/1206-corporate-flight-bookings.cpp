class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffArray(n, 0);
        for (auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seat = booking[2];

            diffArray[first - 1] += seat;
            if (last < n)
                diffArray[last] -= seat;
        }
        for (int i = 1; i < n; i++) {
            diffArray[i] += diffArray[i - 1];
        }
        return diffArray;
    }
};