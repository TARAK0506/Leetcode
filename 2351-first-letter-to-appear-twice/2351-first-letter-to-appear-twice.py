class Solution:
    def repeatedCharacter(self, s: str) -> str:
        l=[]
        for i in s:
            if i in l:
                return i
            l.append(i)