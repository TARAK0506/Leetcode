class Solution {
public:
    vector<string> ans;
    vector<string> letters = {"0", "1"};
    void dfs(string& curr, int n) {
        if (curr.length() == n) {
            ans.emplace_back(curr);
            return;
        }

        curr.push_back('1');
        dfs(curr, n);
        curr.pop_back();
        if (curr.empty() || curr.back() != '0') {
            curr.push_back('0');
            dfs(curr, n);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        if (n == 1)
            return letters;
        string curr = "";
        dfs(curr, n);
        return ans;
    }
};