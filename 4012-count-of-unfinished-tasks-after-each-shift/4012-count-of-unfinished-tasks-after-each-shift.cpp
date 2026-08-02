class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();
        vector<long long> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (i != 0)
                prefix[i] = prefix[i - 1] + tasks[i];
            else
                prefix[i] = tasks[i];
        }
        vector<int> ans(m, 0);
        long long availableTime = 0;
        for (int j = 0; j < m; j++) {
            availableTime += 1LL * shifts[j];
            if (availableTime >= prefix[n - 1]) {
                availableTime = 0;
                ans[j] = 0;
            } else {
                int ub = upper_bound(prefix.begin(), prefix.end(),
                                     1LL * availableTime) -
                         prefix.begin();
                ans[j] = (n - ub);
            }
        }
        return ans;
    }
};