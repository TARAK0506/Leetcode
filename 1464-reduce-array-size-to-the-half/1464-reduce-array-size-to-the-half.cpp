class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for (auto& itr : arr) {
            mp[itr]++;
        }
        for (auto& it : mp) {
            pq.push(make_pair(it.second, it.first));
        }
        int removed = 0, cnt = 0;
        while (!pq.empty()) {
            removed += pq.top().first;
            pq.pop();
            cnt++;
            if (removed >= n / 2)
                return cnt;
        }
        return 0;
    }
};