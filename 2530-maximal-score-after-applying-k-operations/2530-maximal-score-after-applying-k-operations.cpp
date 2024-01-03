class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      long long score=0;
      priority_queue<long long>pq;
      for(auto it:nums){
        pq.push(it);
      }
      while(k!=0 && !pq.empty()){
        score+=pq.top();
        long long val=pq.top();
        pq.push(ceil((val)*1.0/3));
        pq.pop();
        k--;
      }
      return score;
    }
};