class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums) {
            pq.push(it);
        }
        while (pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            if (top < k)
                cnt++;
        }
        return cnt;
    }
};