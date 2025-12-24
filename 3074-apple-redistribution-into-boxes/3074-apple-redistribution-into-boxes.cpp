class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size(), cnt = 0;
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        while(totalApples > 0){
            totalApples -= capacity[cnt];
            cnt++;
        }
        return cnt;
    }
};