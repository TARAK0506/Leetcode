class Solution:
    def minOperations(self, s: str) -> int:
        minOps = 1e9 + 7
        n = len(s)
        cnt1 = cnt2 = 0
        for i in range(n):
            expectOne = "0" if (i & 1) else "1"
            expectZero = "1" if (i & 1) else "0"
            if s[i] != expectOne:
                cnt1 = cnt1 + 1
            if s[i] != expectZero:
                cnt2 = cnt2 + 1
        minOps = min(cnt1, cnt2)
        return minOps
