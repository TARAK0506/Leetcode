bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second){
        return true;
    }
    return false;
}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
        }
        while(!pq.empty()&& k!=0){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            ans.emplace_back(make_pair(pq.top().first,pq.top().second));
            pq.pop();
            k--;
        }
        nums.clear();
        sort(ans.begin(),ans.end(),cmp);
        for(auto it:ans){
            // cout<<it.first<<" "<<it.second<<endl;
            nums.push_back(it.first);
        }
        return nums;
    }
};