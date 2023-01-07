class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int initial_gas=0;
        int start=0;
        int total_gas=0;
        int total_cost=0;
        for(int i=0;i<n;i++)
        {
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        for(int i=0;i<n;i++)
        {
            initial_gas+=gas[i]-cost[i];
            if(initial_gas<0)
            {
                initial_gas=0;
                start=i+1;
            }
            if(total_gas<total_cost)
            {
                return -1;
            }
        }
        return start;
    }
};


/*// int start=0;
        // for(int i=0;i<n;i++)
        // {
        //     intitial_gas+=gas[i]-cost[i];
        //     if(initial_gas<0)
        //     {
        //         initial_gas=0;
        //         start=i+1;
        //     }
        // }
        int tc=0,tg=0;
        for(int i=0;i<n;i++)
        {
            tc+=cost[i];
            tg+=gas[i];
        }
        if(tc>tg) return -1;*/