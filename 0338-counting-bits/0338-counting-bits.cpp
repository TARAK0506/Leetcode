class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            ans=__builtin_popcount(i);
            vec.push_back(ans);
        }
        return vec;
    }
};