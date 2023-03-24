class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            mp2[t[i]]++;
        }
        int cnt=0;
        for(char i=97;i<123;i++)
        {
            if(mp1.find(i)!=mp1.end() && mp2.find(i)!=mp2.end())
                cnt+=abs(mp1[i]-mp2[i]);
            else if(mp1.find(i)!=mp1.end())
                cnt+=mp1[i];
            else if(mp2.find(i)!=mp2.end())
                cnt+=mp2[i];
        }
        return cnt;
    }
};