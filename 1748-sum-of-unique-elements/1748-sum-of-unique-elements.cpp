class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int sum=0;
        for(auto i:mp)
        {
            if(i.second==1)
            {
                sum+=i.first;
            }
        }
        return sum;
    }
};