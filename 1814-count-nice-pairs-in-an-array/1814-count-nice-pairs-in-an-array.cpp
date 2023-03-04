int rev(int n)
{
    int reverse=0;
    while(n!=0)
    {
        int rem=n%10;
        reverse=reverse*10+rem;
        n/=10;
    }
    return reverse;
}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long count=0;
        for(int i=0;i<nums.size();i++)
        {
           nums[i]=nums[i]-rev(nums[i]);
        }
        for(auto it:nums)
        {
            if(mp.find(it)!=mp.end())
            {
                count+=mp[it];
                count%=1000000007;
            }
            mp[it]++;
        }
        return count;
    }
};