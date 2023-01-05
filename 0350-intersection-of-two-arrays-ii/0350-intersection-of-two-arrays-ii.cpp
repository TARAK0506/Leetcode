class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int>vec;
        for(auto i:nums1)
        {
            mp[i]++;
        }
        for(auto i:nums2)
        {
            if(mp.find(i)!=mp.end())
            {
                vec.push_back(i);
                mp[i]--;
                if(mp[i]<1)
                {
                    mp.erase(i);
                }
            }
        }
        return vec;
    }
};