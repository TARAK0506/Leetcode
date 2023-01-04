class Solution:
    def reverseVowels(self, s: str) -> str:
        L=[]
        sol=""
        for i in s:
            if i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U':
                L.append(i)
        a=len(L)-1
        for i in s:
            if i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U':
                sol=sol+L[a]
                a-=1
            else:
                sol=sol+i
        return sol