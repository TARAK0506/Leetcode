class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        l=[]
        ans=[]
        maxi=0
        for i in range(0,len(sentences)):
            l=sentences[i].split()
            ans.append(len(l))
        for i in range(0,len(ans)):
            if maxi<ans[i]:
                maxi=ans[i]
        return maxi
        
    
            