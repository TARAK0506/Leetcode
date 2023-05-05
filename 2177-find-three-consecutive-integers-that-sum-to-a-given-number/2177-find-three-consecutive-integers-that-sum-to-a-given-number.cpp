class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>ans;
        long long n=0;
        if(num%3==0){
            ans.push_back(num/3-1);
            ans.push_back(num/3);
            ans.push_back(num/3+1);
        }
        else{
            return ans;
        }
        return ans;
    }
};