class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        for(auto i:salary)
        {
            cout<<i<<" ";
        }
        int n=salary.size();
        double avg_number=n-2;
        double sum=0;
        for(int i=1;i<salary.size()-1;i++)
        {
            sum+=salary[i];
        }
        return sum/avg_number;
    }
};