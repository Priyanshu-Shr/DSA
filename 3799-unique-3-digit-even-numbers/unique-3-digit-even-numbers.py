class Solution:
    def totalNumbers(self, digits: List[int]) -> int:

        freq = [0]*10
        for i in range(len(digits)):
            freq[digits[i]] += 1

        count = 0

        for i in range(1,10):
            if(freq[i] == 0):
                continue
            
            freq[i]-= 1
            for j in range(10):
                    if(freq[j] == 0):
                        continue
                    
                    freq[j] -= 1
                    for k in range(10):
                        if(freq[k] == 0):
                            continue
                        
                        digit = 100*i + 10*j + k
                        
                        if(digit%2 == 0):
                            count += 1
                    
                    freq[j] += 1
                
            freq[i] += 1
        
        return count
            
