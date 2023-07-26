class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<int>reverse;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int rev=0;
            while(num!=0){
                int rem=num%10;
                rev=rev*10+rem;
                num/=10;
            }
            reverse.emplace_back(rev);
        }
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:reverse){
            if(st.find(it)!=st.end()){
                continue;
            }
            else{
                st.insert(it);
            }
        }
        return st.size();
    }
};