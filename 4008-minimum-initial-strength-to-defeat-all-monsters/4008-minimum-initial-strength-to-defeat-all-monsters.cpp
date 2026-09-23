using ll = long long;
class Solution {
    ll n;

public:
    vector<ll> diffArray(vector<vector<int>>& boosts) {
        vector<ll> bonus(n + 1, 0);
        for (auto& boost : boosts) {
            ll l = boost[0], r = boost[1];
            ll v = boost[2];
            bonus[l] += v;
            if (r + 1 < n) {
                bonus[r + 1] -= v;
            }
        }
        for (int i = 1; i < n; i++) {
            bonus[i] += bonus[i - 1];
        }
        return bonus;
    }
    bool check(vector<int>& monsters, ll strength, vector<ll>& bonus) {
        ll currStrength = strength;
        for (int i = 0; i < n; i++) {
            ll currBonus = bonus[i];
            if (currStrength + currBonus < monsters[i])
                return false;
            currStrength -= monsters[i];
            if (currStrength < 0)
                currStrength = 0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {
        n = monsters.size();
        vector<ll> bonus = diffArray(boosts);
        ll maxStrength = accumulate(begin(monsters), end(monsters), 0LL);
        ll low = 0, high = maxStrength;
        ll minStrength = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(monsters, mid, bonus)) {
                minStrength = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minStrength;
    }
};