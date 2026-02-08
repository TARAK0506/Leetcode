class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            long long curr = nums[i];
            while (!st.empty() && st.top() == curr) {
                long long topEle = st.top();
                st.pop();
                curr = 2 * topEle;
            }
            st.push(curr);
        }
        vector<long long> ans;
        while (!st.empty()) {
            ans.emplace_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};