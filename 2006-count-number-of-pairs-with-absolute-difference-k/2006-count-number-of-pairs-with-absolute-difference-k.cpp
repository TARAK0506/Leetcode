class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=1;j<nums.size();j++)
           {
               if(i<j && abs(nums[i]-nums[j])==k)
               {
                   count++;
               }
           }
       }
        return count;
    }
};