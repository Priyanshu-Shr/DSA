class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        prevAns = 0
        for i in range(len(s)):
            if(s[i] == ' '):
                if(ans != 0):
                    prevAns = ans
                ans = 0
                continue
            else:
                ans += 1
        
        if(ans == 0):
            return prevAns
        else:
            return ans
