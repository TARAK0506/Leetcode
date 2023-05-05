class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
       unordered_map<int,vector<int>>mp;
        for(auto it:nums){
            int a=digitsum(it);
            mp[digitsum(it)].emplace_back(it);
        }
        int maxi=-1;
        for(auto itr:mp)
        {
            sort(itr.second.rbegin(),itr.second.rend());
            if(itr.second.size()>1)
            {
                maxi=max(maxi,itr.second[0]+itr.second[1]);
            }
        }
        return maxi;
    }
};