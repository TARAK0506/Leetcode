class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>vec(n,0);
        for(int i=0;i<n;i++){
            vec[i]=start+2*i;
        }
        int XOR=0;
        for(auto it:vec){
           XOR=XOR^it;
        }
        return XOR;
    }
};