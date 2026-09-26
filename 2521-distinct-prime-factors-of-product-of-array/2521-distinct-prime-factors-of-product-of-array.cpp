class Solution {
    unordered_map<int, int> mp;

public:
    void primeFactors(int n) {
        int num = n;
        while (num % 2 == 0) {
            mp[2] += 1;
            num /= 2;
        }
        for (int i = 3; i * i <= num; i++) {
            while (num % i == 0) {
                mp[i] += 1;
                num /= i;
            }
        }
        if (num > 1) {
            mp[num] += 1;
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            primeFactors(nums[i]);
        }
        for (auto& [key, val] : mp) {
            cout << key << " " << val <<"\n";
        }
        return mp.size();
    }
};