class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto& s:details) {
            int a1 =s[11]-'0';
            int a2 =s[12]-'0';
            if (((a1*10)+ a2 ) > 60) {
                ans++;
            }
        }
        return ans;
    }
};