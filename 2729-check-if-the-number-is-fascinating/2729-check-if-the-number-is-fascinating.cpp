class Solution {
public:
    bool isFascinating(int n) {
        string ans=to_string(n)+to_string(2*n)+to_string(3*n);;
        // cout<<ans<<" ";
        int flag=0;
        map<char,int>mp;
        for(char i=1;i<10;i++){
            mp[i]++;
        }
        for(auto it:ans){
            if(it=='0'){
                continue;
                flag=1;
            }
            else{
                mp[it]--;
            }
        }
        int count=0;
       for(auto it:mp){
         if(it.second==-1){
             count++;
         }
       }   
        if(count==9)
        return true;
        else{
            return false;
        }
    }
};