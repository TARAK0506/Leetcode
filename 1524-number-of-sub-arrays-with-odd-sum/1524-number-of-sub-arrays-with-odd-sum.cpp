class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        long long count=0,sum=0,n=nums.size();
        unordered_map<long long ,long long>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum%=2;
            if(sum==0)
            {
                count++;
            }
            if(mp.find(sum)!=mp.end())
            {
                count+=mp[sum];
            }
            mp[sum]++;
        }
        long long ans=n*(n+1)/2;
       return (ans-count)%1000000007;
    }
};