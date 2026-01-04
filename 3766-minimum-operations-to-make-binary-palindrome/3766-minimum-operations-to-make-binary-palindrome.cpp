class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string dec2Binary(int n) {
        string str = "";
        if (n == 0)
            return "0";
        while (n != 0) {
            str = (char)(n % 2 + '0') + str;
            n /= 2;
        }
        return str;
    }
    vector<int> generateBinaryPalindromes(int maxNum) {
        vector<int> binaryPalindromes(maxNum);
        int n = binaryPalindromes.size();
        for (int i = 1; i <= n; i++) {
            string binary = dec2Binary(i);
            if (isPalindrome(binary)) {
                binaryPalindromes.emplace_back(i);
            }
        }
        return binaryPalindromes;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> binaryPalindromes = generateBinaryPalindromes(5001);
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(binaryPalindromes.begin(),
                                  binaryPalindromes.end(), nums[i]);
            int nearest = INT_MAX;
            if (it != binaryPalindromes.end())
                nearest = abs(*it - nums[i]);
            if (it != binaryPalindromes.begin())
                nearest = min(nearest, abs(*prev(it) - nums[i]));

            ans[i] = nearest;
        }
        return ans;
    }
};