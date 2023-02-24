class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int, greater<int> >s1;
        set<int, greater<int>>::iterator itr;
        for(auto it:banned)
        {
            if(it<=n)
            {
                s1.insert(it);
            }
        }
        // for(itr=s1.begin();itr!=s1.end();itr++)
        // {
        //     cout<<*itr<<" ";
        // }
        // cout<<s1.size()<<endl;
        int sum=0,count=0;
        for(int i=1;i<=n;i++)
        {
            if(s1.find(i)==s1.end())
            {
                sum+=i;
                if(sum<=maxSum)
                {
                    count++;
                }
            }
        }
        return count;
    }
};