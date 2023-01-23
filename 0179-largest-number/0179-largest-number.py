class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        L=[]
        for i in nums:
            L.append(str(i))
        for i in range(len(L)):
            for j in range(i+1,len(L)):
                if L[i]+L[j]<L[j]+L[i] :
                    temp=L[i]
                    L[i]=L[j]
                    L[j]=temp
        ans=''
        for l in L:
            ans+=l
        count=0
        for i in ans:
            if i == "0":
                count+=1
        if count == len(ans):
            return "0"
        else:
            return ans;
                    
                
                    
                    
                
        
            
            
            