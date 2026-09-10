class Solution:
    def isPalindrome(self, s: str) -> bool:
        s =     s.lower()
        temp = ""
        for i in s:
            if( (ord(i) >= ord('a') and ord(i) <= ord('z')) or ord(i) >= ord('0') and ord(i) <= ord('9') ):
                temp += i

        start = 0
        end = len(temp) - 1

        while(start < end):
            if(temp[start] != temp[end]):
                return False
            start += 1
            end -= 1
        
        return True