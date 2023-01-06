class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        L=[]
        nums.sort(reverse =True)
        for i in nums:
            if i not in L:
                L.append(i)
            else:
                continue;
        if len(L)==2 or len(L)==1:
            return L[0]
        else:
            return L[2]
                
        