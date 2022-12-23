class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ::iterator itr;
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        nums.erase(nums.begin(),nums.end());
        for(auto itr:s)
        {
            nums.push_back(itr);
        }
        return nums.size();
    }
};