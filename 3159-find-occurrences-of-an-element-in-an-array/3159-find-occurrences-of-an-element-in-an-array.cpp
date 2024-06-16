class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>freq,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x)
                freq.emplace_back(i);
        }
       for(int i=0;i<queries.size();i++){
         if(queries[i]>freq.size()){
           ans.emplace_back(-1);
         }
         else 
           ans.emplace_back(freq[queries[i]-1]);
       }
      return ans;
    }
};