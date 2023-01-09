class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        vector<int>vec;
        auto maxi=INT_MIN;
        for(auto it:arr)
        {
            mp[it]++;
        }
        for(auto i=mp.rbegin();i!=mp.rend();i++)
        {
            if(i->first == i->second)
            {
                return i->first;
            }
        }
        return -1;
    }
};