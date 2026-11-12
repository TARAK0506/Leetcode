using ll = long long;
class Solution {
    ll n, m;
    vector<int> ans;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        n = servers.size(), m = tasks.size();
        ans.assign(m, 0);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            available;
        for (ll i = 0; i < n; i++) {
            available.push({servers[i], i});
        }
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>,
                       greater<tuple<ll, ll, ll>>>
            occupied;
        ll currTime = 0, timeTaken = 0;
        for (ll j = 0; j < m; j++) {
            currTime = max(currTime, j);
            timeTaken = currTime + tasks[j];
            if (!occupied.empty()) {
                while (!occupied.empty()) {
                    auto [time, weight, idx] = occupied.top();
                    if (time > currTime)
                        break;
                    else {
                        available.push({weight, idx});
                        occupied.pop();
                    }
                }
            }
            if (!available.empty()) {
                auto [weight, idx] = available.top();
                available.pop();
                ans[j] = idx;
                occupied.push({timeTaken, weight, idx});
            } else {
                auto [time, weight, idx] = occupied.top();
                currTime = time;
                timeTaken = currTime + tasks[j];
                while (!occupied.empty()) {
                    auto [time, weight, idx] = occupied.top();
                    if (time > currTime)
                        break;
                    else {
                        available.push({weight, idx});
                        occupied.pop();
                    }
                }
                auto [w, index] = available.top();
                available.pop();
                ans[j] = index;
                occupied.push({timeTaken, w, index});
            }
        }
        return ans;
    }
};