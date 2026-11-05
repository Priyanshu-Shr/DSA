class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0
        for i in range(len(arr1)):
            a = arr1[i]
            j = 0
            while(j<len(arr2)):
                if abs(a-arr2[j]) <=d:
                    break
                j += 1
            
            if(j == len(arr2)):
                ans+= 1

        return ans