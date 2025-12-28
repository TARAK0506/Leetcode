class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        long long type1 = (long long)need1 * cost1;
        long long type2 = (long long)need2 * cost2;
        if (cost1 + cost2 < costBoth) {
            ans = type1 + type2;
        } else {
            ans += (long long)min(need1, need2) * costBoth;
            if (need1 < need2)
                ans += (long long)(need2 - need1) * min(cost2, costBoth);
            else
                ans += (long long)(need1 - need2) * min(cost1, costBoth);
        }
        return ans;
    }
};
