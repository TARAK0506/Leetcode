class Solution {
    vector<int> div;
    vector<int> res;
    int minDiff = INT_MAX;

public:
    vector<int> getDivisors(int n) {
        vector<int> div;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.emplace_back(i);
                if (n / i != i)
                    div.emplace_back(n / i);
            }
        }
        sort(begin(div), end(div));
        return div;
    }
    int getMinDiff(vector<int>& curr) {
        int maxVal = *max_element(curr.begin(), curr.end());
        int minVal = *min_element(curr.begin(), curr.end());
        return maxVal - minVal;
    }
    void dfs(int n, vector<int>& path, int k, int idx) {
        if (k == 0) {
            if (n == 1) {
                int diff = getMinDiff(path);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = path;
                }
            }
            return;
        }
        for (int i = idx; i < div.size(); i++) {
            int d = div[i];
            if (d > n)
                break;
            if (n % d != 0)
                continue;
            path.emplace_back(d);
            dfs(n / d, path, k - 1, i);
            path.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        div = getDivisors(n);
        vector<int> path;
        dfs(n, path, k, 0);
        return res;
    }
};