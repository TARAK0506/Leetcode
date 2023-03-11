class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-2*diff)!=mp.end() && mp.find(nums[i]-diff)!=mp.end())
            {
                count++;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};