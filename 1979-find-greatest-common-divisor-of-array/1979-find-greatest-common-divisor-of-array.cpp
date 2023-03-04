class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int smallest=nums[0],largest=nums[nums.size()-1];
        int ans=__gcd(smallest,largest);
        return ans;
    }
};