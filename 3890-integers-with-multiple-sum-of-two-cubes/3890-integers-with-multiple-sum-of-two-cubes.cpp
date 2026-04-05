class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> mp;
        for (int a = 1; a <= 1000; a++) {
            for (int b = a; b <= 1000; b++) {
                long long x = a * a * a + b * b * b;
                if (x > n)
                    break;
                mp[x]++;
            }
        }
        vector<int> ans;
        for (auto& [key, val] : mp) {
            if (val >= 2) {
                ans.emplace_back(key);
            }
        }
        return ans;
    }
};