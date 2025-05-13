class Solution {
public:
    int minDeletion(string s, int k) {
        int cnt = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<char, int> mp;
        for (auto& ch : s) {
            if (mp.find(ch) == mp.end())
                cnt++;
            mp[ch]++;
        }
        for (auto& [key, val] : mp) {
            pq.push(val);
        }
        while (!pq.empty() && cnt > k) {
            ans += pq.top();
            pq.pop();
            cnt--;
        }
        return ans;
    }
};