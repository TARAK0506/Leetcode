class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(auto it:gifts){
            pq.push(it);
        }
        while(!pq.empty() && k!=0){
            // cout<<pq.top()<<" "<<endl;
            int top1=pq.top();
            pq.push(floor(sqrt(top1)));
            k--;
            pq.pop();
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};