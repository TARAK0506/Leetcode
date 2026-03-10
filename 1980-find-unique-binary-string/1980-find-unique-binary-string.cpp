class Solution {
public:
    string ans = "";
    void backtrack(int n, string& curr, unordered_set<string> st) {
        if (!ans.empty())
            return;
        if (curr.length() == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }
        curr.push_back('0');  
        backtrack(n, curr, st);
        curr.pop_back();  
        curr.push_back('1');
        backtrack(n, curr, st);
        curr.pop_back();  
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