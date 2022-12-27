class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                vec.push_back(i);
            }
        }
        vector<int> ans;
        if(vec.size()==0)
        {
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        else
        {
            if(vec.size()==1)
            {
                for(auto i:vec)
                {
                    ans.push_back(i);
                    ans.push_back(i);
                }
                return ans;
            }
            if(vec.size()==2)
            {
                return vec;
            }
            else
            {
                vec.erase(vec.begin()+1,vec.end()-1);
                return vec;
            }
        }
        //return vec;
    }
};