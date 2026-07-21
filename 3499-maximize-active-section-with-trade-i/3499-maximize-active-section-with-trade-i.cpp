class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length(), cnt = 0, maxx = INT_MIN, cntOnes = 0;
        vector<int> values;
        char prev;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cntOnes++;
                if (prev == '0')
                    values.emplace_back(cnt);
                cnt = 0;
            } else {
                cnt -= 1;
            }
            prev = s[i];
        }
        if (cnt < 0 || prev == '0')
            values.emplace_back(cnt);
        int prevv = 1;
        if (cntOnes == 0 || cntOnes == n || values.size() == 1)
            return cntOnes;
        for (int i = 1; i < values.size(); i++) {
            maxx = max(maxx, abs(values[i - 1] + values[i]));
        }
        return maxx + cntOnes;
    }
};