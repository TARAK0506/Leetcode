using ll = long long;
class Solution {
    int n;

public:
    int minMoves(vector<int>& nums) {
        n = nums.size();
        ll sum = accumulate(begin(nums), end(nums), 0LL);
        ll minEle = *min_element(begin(nums), end(nums));
        ll moves = sum - 1LL * n * minEle;
        return moves;
    }
};