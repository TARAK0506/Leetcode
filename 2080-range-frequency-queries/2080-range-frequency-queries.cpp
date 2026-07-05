class RangeFreqQuery {
    int n, blockSize;
    vector<int> nums;
    vector<unordered_map<int, int>> rangeFreq;

public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        blockSize = ceil(sqrt(n));
        int blockIndex = -1;
        rangeFreq.resize(blockSize);
        for (int i = 0; i < n; i++) {
            if (i % blockSize == 0) {
                blockIndex++;
            }
            rangeFreq[blockIndex][nums[i]]++;
        }
    }

    int query(int left, int right, int value) {
        int ans = 0;
        while (left <= right && (left % blockSize) != 0 && left != 0) {
            if (nums[left] == value)
                ans++;
            left++;
        }
        while (left + blockSize - 1 <= right) {
            ans += rangeFreq[left / blockSize][value];
            left += blockSize;
        }
        while (left <= right) {
            if (nums[left] == value)
                ans++;
            left++;
        }
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */