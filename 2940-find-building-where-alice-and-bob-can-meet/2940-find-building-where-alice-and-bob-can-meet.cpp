class Solution {
private:
    int n;
    vector<int> seg;
    vector<int> ans;
    void buildTree(int node, int low, int high, vector<int>& heights) {

        if (low == high) {
            seg[node] = low;
            return;
        }

        int mid = low + (high - low) / 2;
        buildTree(2 * node + 1, low, mid, heights);
        buildTree(2 * node + 2, mid + 1, high, heights);

        int leftIdx = seg[2 * node + 1];
        int rightIdx = seg[2 * node + 2];

        seg[node] =
            (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int rangeMinIndex(int node, int low, int high, int left, int right,
                      vector<int>& heights) {
        if (low > right || high < left)
            return -1;
        if (left <= low && high <= right)
            return seg[node];

        int mid = low + (high - low) / 2;
        int leftIdx =
            rangeMinIndex(2 * node + 1, low, mid, left, right, heights);
        int rightIdx =
            rangeMinIndex(2 * node + 2, mid + 1, high, left, right, heights);
        if (leftIdx == -1)
            return rightIdx;
        if (rightIdx == -1)
            return leftIdx;

        return (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        n = heights.size();
        seg.resize(4 * n);
        buildTree(0, 0, n - 1, heights);
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int leftIdx = min(a, b);
            int rightIdx = max(a, b);
            if (leftIdx == rightIdx) {
                ans.emplace_back(leftIdx);
            } else if (heights[rightIdx] > heights[leftIdx]) {
                ans.emplace_back(rightIdx);
            } else {
                int low = rightIdx + 1, high = n - 1;
                int answer = -1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int idx = rangeMinIndex(0, 0, n - 1, low, mid, heights);
                    if (idx != -1 && heights[idx] > heights[leftIdx]) {
                        high = mid - 1;
                        answer = idx;

                    } else {
                        low = mid + 1;
                    }
                }
                ans.emplace_back(answer);
            }
        }
        return ans;
    }
};