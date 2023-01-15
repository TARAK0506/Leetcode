class Solution {
public:
    string largestGoodInteger(string num) {
        int count=0;
        string ans="";
        for(int i=2;i<num.size();i++)
        {
            if(num[i]== num[i-1] &&num[i-1]==num[i-2])
           {
                count++;
                ans=max(ans,num.substr(i-2,3));
           }
        }
        return ans;
    }
};