class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> st;
        int totalBinaryCodes = (1 << k);
        for (int i = k; i <= n; i++) {
            string str = s.substr(i - k, k);
            if (!st.count(str)) {
                st.insert(str);
                totalBinaryCodes--;
            }
            if (totalBinaryCodes == 0) {
                return true;
            }
        }
        return false;
    }
};