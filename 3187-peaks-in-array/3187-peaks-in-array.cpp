class Solution {
    int n;
    vector<int> seg;
    vector<int> peaks;
    vector<int> ans;
    void buildTree(int node, int low, int high) {
        if (low == high) {
            seg[node] = peaks[low];
            return;
        }
        int mid = low + (high - low) / 2;
        buildTree(2 * node + 1, low, mid);
        buildTree(2 * node + 2, mid + 1, high);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int query(int node, int low, int high, int left, int right) {
        if (right < low || high < left)
            return 0;

        if (left <= low && high <= right) {
            return seg[node];
        }

        int mid = low + (high - low) / 2;
        int leftCnt = query(2 * node + 1, low, mid, left, right);
        int rightCnt = query(2 * node + 2, mid + 1, high, left, right);
        return leftCnt + rightCnt;
    }

    void update(int node, int low, int high, int index, int value) {
        if (low == high) {
            seg[node] = value;
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid) {
            update(2 * node + 1, low, mid, index, value);
        } else {
            update(2 * node + 2, mid + 1, high, index, value);
        }
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int rangeQuery(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    void pointUpdate(int index, int value) {
        update(0, 0, n - 1, index, value);
    }

public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        seg.resize(4 * n);
        peaks.assign(n, 0);
        auto isPeak = [&](int idx) {
            if (idx <= 0 || idx >= n - 1)
                return false;
            return nums[idx - 1] < nums[idx] && nums[idx] > nums[idx + 1];
        };

        for (int i = 0; i < n; i++) {
            peaks[i] = isPeak(i);
        }

        buildTree(0, 0, n - 1);

        for (int i = 0; i < queries.size(); i++) {
            int type = queries[i][0];
            if (type == 1) {
                int left = queries[i][1] + 1, right = queries[i][2] - 1;
                if (left > right) {
                    ans.emplace_back(0);
                } else {
                    int cnt = rangeQuery(left, right);
                    ans.emplace_back(cnt);
                }
            } else {
                int index = queries[i][1], value = queries[i][2];
                nums[index] = value;
                for (int i = index - 1; i <= index + 1; i++) {
                    if (i >= 0 && i < n) {
                        peaks[i] = isPeak(i);
                        pointUpdate(i, peaks[i]);
                    }
                }
            }
        }
        return ans;
    }
};