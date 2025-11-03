class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0, n = colors.length();
        int minTime = 0;
        while (i < n && j < n) {
            int currTime = 0, currMax = 0;
            int j = i;
            while (j < n && colors[i] == colors[j]) {
                currTime += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            minTime += currTime - currMax;
            i = j;
        }
        return minTime;
    }
};