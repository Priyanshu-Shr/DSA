class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int m = n;

        while(m){
            int digit = m%10;
            sum += digit;
            product *= digit;
            m = m/10;
        }

        int temp = sum + product;
        if(n%temp == 0)
            return true;
        
        return false;
    }
};