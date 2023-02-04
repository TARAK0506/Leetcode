class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=arr[arr.size()-1];
        map<int,int> mp;
        vector<int> vec;
        for(auto i:arr)
        {
            mp[i]++;
        }
        for(int i=1;i<=num+k;i++)
        {
            if(mp.find(i)==mp.end())
            {
                vec.push_back(i);
            }
        }
        int ans=vec[k-1];
        return ans;
    }
};