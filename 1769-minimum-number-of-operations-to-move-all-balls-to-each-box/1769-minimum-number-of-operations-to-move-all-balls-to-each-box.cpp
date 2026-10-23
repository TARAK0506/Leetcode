class Solution {
    int n;
    vector<int> answer;

public:
    vector<int> minOperations(string boxes) {
        n = boxes.length();
        answer.assign(n, 0);
        int cnt = 0, ops = 0;
        for (int i = 0; i < n; i++) {
            answer[i] += ops;
            cnt += (boxes[i] == '1' ? 1 : 0);
            ops += cnt;
        }
        cnt = 0, ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += ops;
            cnt += (boxes[i] == '1' ? 1 : 0);
            ops += cnt;
        }
        return answer;
    }
};