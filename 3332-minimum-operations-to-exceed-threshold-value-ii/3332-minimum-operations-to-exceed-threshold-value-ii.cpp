class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto it : nums) {
            pq.push(it);
        }
        int cnt = 0;
        while (pq.size() > 1) {
            long long  x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long add = min(x, y) * 2 + max(x, y);
            pq.push(add);
            if (x < k)
                cnt++;
        }
        return cnt;
    }
};