class Solution {
    int n;
    vector<string> answer;

public:
    vector<string> assignUmbrella(vector<int>& rain) {
        n = rain.size();
        answer.assign(n, "");
        int cntA = 0, cntB = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && rain[i] == 1 && rain[i + 1] == 1 && cntA <= cntB) {
                cntA += 1;
                answer[i] = "Alice";
            } else if (rain[i] == 1) {
                cntB += 1;
                answer[i] = "Bob";
            } else {
                answer[i] = "None";
            }
        }
        return answer;
    }
};