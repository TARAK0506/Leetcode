class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int>s1,s2,s3;
        map<int,int>mp1,mp2,mp3;
        vector<int>ans;
        for(auto it:nums1){
            s1.insert(it);
        }
        for(auto it:nums2){
            s2.insert(it);
        }
        for(auto it:nums3){
            s3.insert(it);
        }
        for(auto itr:s1){
            mp1[itr]++;
        }
        for(auto itr:s2){
            mp1[itr]++;
        }
        for(auto itr:s3){
            mp1[itr]++;
        }
        for(auto it:mp1){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};