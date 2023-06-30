class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int>ans;
        ans.emplace_back(first);
        int temp=first;
        for(int i=0;i<n;i++){
            temp=encoded[i]^temp;
            ans.push_back(temp);
        }
        return ans;
    }
};