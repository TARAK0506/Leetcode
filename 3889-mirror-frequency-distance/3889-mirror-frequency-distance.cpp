class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> charFreq(26, 0);
        vector<int> digitFreq(10, 0);
        for (auto& ch : s) {
            if (isalpha(ch)) {
                charFreq[ch - 'a']++;
            } else {
                digitFreq[ch - '0']++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 13; i++) {
            int mirror = 25 - i;
            ans += abs(charFreq[i] - charFreq[mirror]);
        }
        for (int i = 0; i < 5; i++) {
            int mirror = 9 - i;
            ans += abs(digitFreq[i] - digitFreq[mirror]);
        }
        return ans;
    }
};