class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vec;
        while(num!=0)
        {
            int rem=num%10;
            vec.push_back(rem);
            num/=10;
        }
        int c=0;
        int ans=0;
        int n=vec.size();
        for(int i=n-1;i>=0;i--)
        {
            if(vec[i]==6 && c==0)
            {
                vec[i]=9;
                c=1;
            }
            ans=ans*10+vec[i];
        }
        return ans;
    }
};