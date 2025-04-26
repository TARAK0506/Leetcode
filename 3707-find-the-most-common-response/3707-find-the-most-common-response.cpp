class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string> p1, pair<int, string> p2) {
            if (p1.first == p2.first) {
                return p2.second < p1.second;
            }
            return p1.first < p2.first;
        }
    };
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mp;
        for (auto& day : responses) {
            unordered_set<string> st(day.begin(), day.end());
            for (auto& it : st) {
                mp[it]++;
            }
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto& it : mp) {
            // cout << it.first << " " << it.second << endl;
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            // cout << pq.top().first << " " << pq.top().second << endl;
            ans = pq.top().second;
            pq.pop();
            break;
        }
        return ans;
    }
};