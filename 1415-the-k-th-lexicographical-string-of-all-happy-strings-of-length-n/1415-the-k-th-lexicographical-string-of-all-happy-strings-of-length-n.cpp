class Solution {
public:
    vector<char> letters = {'a', 'b', 'c'};
    string ans;
    void backtrack(int n, int length, int& k, string& curr) {
        if (length == n) {
            k--;
            if (k == 0) {
                ans = curr;
                return;
            }
        }

        if (length != n) {
            for (auto& ch : letters) {
                if (curr.empty() || curr.back() != ch) {
                    curr.push_back(ch);
                    backtrack(n, length + 1, k, curr);
                    curr.pop_back();
                    if (!ans.empty())
                        return;
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        int length = 0;
        backtrack(n, length, k, curr);
        return ans;
    }
};