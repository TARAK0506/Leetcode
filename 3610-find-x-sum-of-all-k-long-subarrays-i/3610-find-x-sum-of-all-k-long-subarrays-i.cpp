class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p2.first > p1.first;
        return p2.second > p1.second;
    }

    int x_sum(vector<int>& nums, int x) {
        int sum = 0;
        unordered_map<int, int> freq;
        for (auto& it : nums) {
            freq[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       function<bool(pair<int, int>, pair<int, int>)>>
            pq(compare);

        for (auto& pair : freq) {
            pq.push({pair.first, pair.second});
        }

        while (!pq.empty() && x > 0) {
            auto top = pq.top();
            pq.pop();
            sum += top.second * top.first;
            x--;
        }
        return sum;
    }
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> answer;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n - k; i++) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            int sum = x_sum(subarray, x);
            answer.emplace_back(sum);
        }
        return answer;
    }
};