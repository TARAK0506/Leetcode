class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        int ans;
        for(auto it:mp)
        {
            if(it.second>=arr.size()*0.25)
            {
                ans=it.first;
            }
        }
        return ans;
    }
};