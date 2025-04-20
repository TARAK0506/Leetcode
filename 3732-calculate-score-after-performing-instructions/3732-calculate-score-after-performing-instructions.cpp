class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        int i = 0, n = instructions.size();
        long long initial_score = 0;
        vector<int> visited(n, 0);
        while (i >= 0 && i < n && !visited[i]) {
            visited[i] = 1;
            if (instructions[i] == "add") {
                initial_score += values[i];
                i++;
            } else if(instructions[i] == "jump") {
                i = (i + values[i]);
            }
        }
        return initial_score;
    }
};