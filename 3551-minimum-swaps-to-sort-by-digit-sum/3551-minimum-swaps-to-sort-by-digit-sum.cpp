class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), minSwap = 0;
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({digitSum(nums[i]), i});
        }
        sort(begin(arr), end(arr), [&](const auto& a, const auto& b) {
            if (a.first == b.first)
                return nums[a.second] < nums[b.second];
            return a.first < b.first;
        });
        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++) {
            if (isVisited[i] || arr[i].second == i)
                continue;
            int steps = 0;
            int j = i;
            while (!isVisited[j]) {
                isVisited[j] = true;
                j = arr[j].second;
                steps += 1;
            }
            minSwap += steps - 1;
        }
        return minSwap;
    }
};