import math
class Solution:
    def check(self, dist, hour, speed):
        n = len(dist)
        time = 0
        for i in range(0, n - 1):
            time += math.ceil(dist[i] / speed)
        time += dist[n - 1] / speed
        return time <= hour

    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        low, high = 1, 1e8
        ans = -1
        while low <= high:
            mid = (low + high) // 2
            if self.check(dist, hour, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return int(ans)
