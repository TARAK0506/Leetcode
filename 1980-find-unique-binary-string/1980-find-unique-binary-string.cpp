class Solution {
public:
    string ans = "";
    void backtrack(int n, string curr, unordered_set<string> st) {
        if (!ans.empty())
            return;
        if (curr.length() == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }

        backtrack(n, curr + "0", st);
        backtrack(n, curr + "1", st);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for (auto& str : nums) {
            st.insert(str);
        }
        string curr = "";
        backtrack(n, curr, st);
        return ans;
    }
};