class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long maxi=0,n=nums.size(),ans=0,sum;
        vector<long long>vec;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(long long)nums[i]);
            sum=nums[i]+maxi;
            ans+=sum;
            vec.push_back(ans);
        }
        return vec;
    }
};