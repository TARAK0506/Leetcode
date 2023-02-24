class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            string concat=to_string(nums[i])+to_string(nums[j]);
            ans+=stoi(concat);
            i++;
            j--;
        }
        if(nums.size()%2!=0)
        {
            ans+=nums[nums.size()/2];
            return ans;
        }
        return ans;
    }
};