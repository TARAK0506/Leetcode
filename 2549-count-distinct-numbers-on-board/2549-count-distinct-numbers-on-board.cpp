class Solution {
public:
   int distinctIntegers(int n) {
    vector<int> vec;
    map<int,int> mp;
    while(n>0)
    {
         for(int i=1;i<n;i++)
         {
             if(n%i==1)
             {
                vec.push_back(i);
             }
         }
        n--;
     }
     for(auto it:vec)
     {
         mp[it]++;
     }
     int ans=mp.size()+1;
      return ans;
    }
};