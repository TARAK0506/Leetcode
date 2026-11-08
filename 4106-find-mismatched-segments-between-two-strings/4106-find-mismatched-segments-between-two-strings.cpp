class Solution {
    int n;
    vector<vector<string>> seg;

public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        n = s1.length();
        int i = 0;
        while (i < n) {
            if (s1[i] == s2[i]) {
                i += 1;
                continue;
            }
            int startIdx = i;
            while (i < n && s1[i] != s2[i]) {
                i++;
            }
            int endIdx = i - startIdx;
            seg.push_back({s1.substr(startIdx, endIdx), s2.substr(startIdx, endIdx)});
        }
        return seg;
    }
};