class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (26 - (s[i] - 'a')) * (i+1);
        }
        return sum;
    }
};