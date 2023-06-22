class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int>vec;
        int cnt=0,even=0,odd=0;
        while(n){
            if(n&1==1){
                if(cnt%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
            cnt++;
            n=n>>1;
        }
        vec.emplace_back(even);
        vec.emplace_back(odd);
        return vec;
    }
};