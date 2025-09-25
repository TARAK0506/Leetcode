class Solution {
public:
    bool canDistribute(vector<int>& quantities, int mid, int n) {
        int cnt = 0;
        for (int i = 0; i < quantities.size(); i++) {
            cnt += ceil((double)quantities[i] / (double)mid);
        }
        return cnt <= n;
    }
    int findMax(vector<int>& quantities) {
        int maxi = INT_MIN;
        for (auto& num : quantities) {
            if (maxi < num) {
                maxi = num;
            }
        }
        return maxi;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int low = 1, high = findMax(quantities);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(quantities, mid, n))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};