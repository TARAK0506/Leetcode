class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
      priority_queue<int,vector<int>,greater<int>>pq;
      for(int &num:nums){
        pq.push(num);
      }
      while(!pq.empty()){
        int alice=pq.top();
        pq.pop();
        int bob=pq.top();
        pq.pop();
        ans.emplace_back(bob);
        ans.emplace_back(alice);
      }
      return ans;
    }
};