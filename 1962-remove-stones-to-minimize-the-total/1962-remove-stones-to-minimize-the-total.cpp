class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(!pq.empty() && k!=0){
            int pile=floor(pq.top()/2);
            int top=pq.top();
            // cout<<top<<" ";
            pq.pop();
            int ans=top-pile;
            pq.push(ans);
            // pq.pop();
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            // cout<<pq.top()<<" ";
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};