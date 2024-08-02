class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
         if (intervals.empty()) {
            return {};
        }
        vector<vector<int>>ans;
        ans.emplace_back(intervals[0]);
        for (int i=1;i<intervals.size(); ++i) {
            vector<int>&last=ans.back();
            if(intervals[i][0]<=last[1]) {
                last[1]=max(last[1], intervals[i][1]);
            }
            else{
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};