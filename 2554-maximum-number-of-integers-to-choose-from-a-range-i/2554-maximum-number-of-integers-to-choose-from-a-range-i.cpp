class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int sum=0,count=0;
        unordered_map<int,int> m;
        for(auto i : banned) m[i]++;
        for(int i=1;i<=n;i++)
        {
            sum=sum+i;
            if(!m[i] && sum<=maxSum)
            {
                count++;
            }
            else
            {
                sum=sum-i;
            }
        }
        return count;
    }
};