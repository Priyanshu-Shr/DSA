class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i]<0 :
                nums[i] = - nums[i]
            
        nums.sort()
        n = len(nums)
        ans = 0
        x = int(n/2)
        for i in range(0,x):
            ans -= nums[i]*nums[i]
        
        for i in range(x , n):
            ans += nums[i]*nums[i]
        
        return ans