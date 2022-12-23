class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        st=s.split()
        ans=len(st[-1])
        return ans
        
        