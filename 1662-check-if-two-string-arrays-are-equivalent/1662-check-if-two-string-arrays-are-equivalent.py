class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        ans=''.join(word1[:len(word1)])
        ans1=''.join(word2[:len(word2)])
        if ans==ans1:
            return True
        else:
            return False