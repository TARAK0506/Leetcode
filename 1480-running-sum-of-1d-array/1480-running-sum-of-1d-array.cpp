class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            vec.push_back(sum);
        }
        return vec;
    }
};