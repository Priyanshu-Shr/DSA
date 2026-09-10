class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = float('inf')
        max_profit = 0

        for x in prices:
            if(x<mini):
                mini = x
            if(x-mini > max_profit):
                max_profit = x - mini

        return max_profit