class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int numR=grid.size();
        int numC=grid[0].size();
        for(int i=0;i<numR;i++){
            for(int j=0;j<numC;j++){
                if(grid[i][j]<0){
                    ans++;
                }
            }
        }
        return ans;
    }
};