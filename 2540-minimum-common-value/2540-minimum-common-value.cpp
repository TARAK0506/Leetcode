class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s,s1;
        for(int i=0;i<nums1.size();i++)
        {
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            s1.insert(nums2[i]);
        }
        // set<int> ::iterator it;
        // for(it=s.begin();it!=s.end();it++)
        // {
        //     cout<<*it<<" "<<endl;
        // }
        map<int,int> mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:s1)
        {
            mp[i]--;
        }
        for(auto it:mp)
        {
            if(it.second==0)
            {
                return it.first;
                break;
            }
        }
        return -1;
    }
};