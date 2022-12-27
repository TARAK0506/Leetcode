class Solution {
public:
    int strStr(string haystack, string needle) {
        int a=haystack.size();
        int b=needle.size();
        for(int i=0;i<=a-b;i++)
        {
            int c=0;
            int n=i;
            while(c<b && haystack[n]==needle[c])
            {
                c++;
                n++;
            }
            if(c==b)
            {
                return i;
            }
        }
        return -1;
    }
};