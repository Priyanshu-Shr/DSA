class Solution:
    def countOdds(self, low: int, high: int) -> int:
        ans = 0
        if( (low&1) and (high&1) ):
            ans = (high-low)//2 + 1
        elif( (low&1)==0 and (high&1)==0 ):
            ans = (high-low)//2 
        else:
            ans = (high-low)//2 + 1
        
        return ans