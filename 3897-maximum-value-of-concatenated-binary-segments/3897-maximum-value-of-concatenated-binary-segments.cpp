class Solution {
    const int MOD = 1e9 + 7;

public:
    int bin2Dec(string& s) {
        int decimal = 0;
        for (auto& ch : s) {
            decimal = (decimal * 2 + (ch - '0')) % MOD;
        }
        return decimal;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<string> seg;
        for (int i = 0; i < n; i++) {
            int ones = nums1[i], zeros = nums0[i];
            string s1, s2;
            s1 = string(ones, '1');
            s2 = string(zeros, '0');
            seg.push_back(s1 + s2);
        }
        sort(begin(seg), end(seg),
             [](const auto& a, const auto& b) { return (a + b) > (b + a); });
        string str = "";
        for (auto& it : seg) {
            str += it;
        }
        return bin2Dec(str);
    }
};