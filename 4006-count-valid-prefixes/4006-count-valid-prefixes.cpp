class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.length();
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            prefix[i] = (s[i] == '0' ? -1 : 1);
        }
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            ans += prefix[i];
            if(ans == 0 || ans == -1 || ans == 1){
                cnt++;
            } 
        }
        return cnt;
    }
};