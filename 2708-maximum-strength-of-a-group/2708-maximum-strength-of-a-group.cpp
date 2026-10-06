using ll = long long;
class Solution {
    ll n, prod;
    vector<ll> product;

public:
    void dfs(int idx, ll prod, vector<int>& nums) {
        if (idx == n) {
            return;
        }
        for (int i = idx; i < n; i++) {
            product.emplace_back(prod * nums[i]);
            dfs(i + 1, prod * nums[i], nums);
        }
    }
    long long maxStrength(vector<int>& nums) {
        n = nums.size(), prod = 1;
        dfs(0, prod, nums);
        ll maxStrength = LLONG_MIN;
        for (auto& ele : product)
            maxStrength = max(maxStrength, ele);
        return maxStrength;
    }
};