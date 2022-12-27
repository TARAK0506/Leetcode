class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]];
        }
        /*for(auto i:mp)
        {
            cout<<i.first<<" ";
        }*/
        vector<int> vec;
        for(int i=1;i<=nums.size();i++)
        {
            if(mp.find(i)==mp.end())
            {
                vec.push_back(i);
            }
        }
       return vec;
    }
};