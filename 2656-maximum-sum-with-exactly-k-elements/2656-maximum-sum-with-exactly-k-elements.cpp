class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        int sum=0;
        while(!pq.empty() & k!=0)
        {
            int n=pq.top();
            pq.pop();
            pq.push(n+1);
            sum+=n;
            k--;
        }
        return sum;
    }
};