class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.split(" ")
        s=s[::-1]
        s=' '.join([str(item) for item in s])
        s=s.strip(" ")
        s=" ".join(s.split())
        return s