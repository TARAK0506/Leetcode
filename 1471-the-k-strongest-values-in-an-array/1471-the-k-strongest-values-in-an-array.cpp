class Solution {
public:
    vector<int> getStrongest(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[(n-1)/2];
        int low=0,high=n-1;
        while(k!=0 && low<=high)
        {
            if(abs(nums[low]-median)>abs(nums[high]-median))
            {
                ans.push_back(nums[low]);
                low++;
            }
            else
            {
                ans.push_back(nums[high]);
                high--;
            }
            k--;
        }
        return ans;
    }
};