class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> mp;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key)
            {
                mp[nums[i+1]]++;
            }
        }
        int freq=INT_MIN,ans;
        for(auto it:mp)
        {
            if(it.second>freq)
            {
                freq=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};