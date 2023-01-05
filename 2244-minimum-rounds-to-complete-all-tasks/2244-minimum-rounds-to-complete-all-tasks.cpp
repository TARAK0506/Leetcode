class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        map<int,int> mp;
        map<int,int> ::iterator itr=mp.begin();
        for(auto i:tasks)
        {
            mp[i]++;
        }
        int count=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second==1)
            {
                return -1;
            }
            else if(itr->second==2)
            {
                count+=1;
            }
            else if(itr->second%3==0)
            {
                count+=itr->second/3;
            }
            else
            {
                count+=itr->second/3 +1;
            }
        }
        return count;
    }
};