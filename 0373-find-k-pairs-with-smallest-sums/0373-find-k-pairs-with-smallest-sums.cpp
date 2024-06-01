class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector< vector<int> > ans;
       priority_queue< pair<int,pair<int,int>>>pq;
        for(auto it : nums1){
            for(auto itr : nums2){
                int sum=it+itr;
                if(pq.size()<k){
                    pq.push({sum,{it,itr}});
                }
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{it,itr}});
                }
              else break;
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
}; 