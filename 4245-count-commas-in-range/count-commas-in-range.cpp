class Solution {
public:
    int countCommas(int n) {
        
        if(n >= 1000){
            int count = n-999;
            return count;
        }else{
            return 0;
        }
    }
};