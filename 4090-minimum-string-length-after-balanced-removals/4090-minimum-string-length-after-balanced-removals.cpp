class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a')
                cnt++;
            else
                cnt--;
        }
        return abs(cnt);
    }
};