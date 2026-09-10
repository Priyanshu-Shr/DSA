class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        st = set()

        for x in nums:
            if x in st:
                return True
            else:
                st.add(x)
    
        return False