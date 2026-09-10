class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}

        for i in range(len(nums)):
            needed = target - nums[i]

            if needed in mp:
                return [mp[needed],i]
            
            mp[nums[i]] = i