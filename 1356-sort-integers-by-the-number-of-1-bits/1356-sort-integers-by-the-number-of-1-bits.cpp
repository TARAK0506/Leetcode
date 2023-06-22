int count(int n){
    int cnt=0;
    while(n!=0){
        if((n&1)==1){
            cnt++;
        }
        n=n>>1;
    }
    return cnt;
}
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    if(p1.second<p2.second){
        return true;
    }
    return false;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vec;
        for(int i=0;i<arr.size();i++){
            vec.emplace_back(make_pair(arr[i],count(arr[i])));
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>ans;
        for(auto it:vec){
            ans.emplace_back(it.first);
        }
        return ans;
    }
};