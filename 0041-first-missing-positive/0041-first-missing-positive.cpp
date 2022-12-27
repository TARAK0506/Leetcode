class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // smallest_positive_integer=1;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]];
        }
       /* for(auto i:mp)
        {
            cout<<i.first<<" ";
        }*/
        // cout<<mp.rbegin()->first;
        int it;
        for(it=1;it<=mp.rbegin()->first;it++) 
        {
            if(mp.find(it)==mp.end())
            {
                return it;
            }
        }
        return it;
    }
};