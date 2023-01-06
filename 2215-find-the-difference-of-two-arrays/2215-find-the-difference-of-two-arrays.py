class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        nums1=set(nums1)
        nums2=set(nums2)
        L=[]
        L1=[]
        for i in nums1:
            L.append(i)
        for i in nums2:
            if i not in nums1:
                L1.append(i)
        L2=[]
        L3=[]
        for i in nums2:
            L2.append(i)
        for i in nums1:
            if i not in nums2:
                L3.append(i)
        L5=[]
        L5.append(L3)
        L5.append(L1)
        return L5