class Solution {
public:
    bool digitCount(string num) {
        map<int,int>mp,mp1;
        map<int,int> ::iterator it;
        for(auto i:num)
        {
            mp1[i]++;
        }
        int i;
        for(int i=0;i<num.size();i++)
        {
            mp[i]=mp1[i+48];
        }
        for(i=0,it=mp.begin();i<num.size();i++,it++)
        {
            if(it->second+48!=int(num[i]))
            {
                return false;
            }
        }
        return true;
    }
};