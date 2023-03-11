class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
    }
};