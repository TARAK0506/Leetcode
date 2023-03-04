class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int>ans,vec(2,0);
        vec[0]=0,vec[1]=1;
        unordered_map<int,int>mp;
        if(nums.size()==1)
        {
            return vec;
        }
        for(auto it:nums)
        {
            mp[it]++;
        }
        int count=0,an=0;
        for(auto itr:mp)
        {
            if(itr.second>=2)
            {
                count+=itr.second/2;
            }
            if(itr.second%2!=0)
            {
                an+=itr.second%2;
            }
        }
        ans.push_back(count);
        ans.push_back(an);
        return ans;
    }
};